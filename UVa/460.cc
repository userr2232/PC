#include <iostream>
#include <algorithm>

using namespace std;

struct vec {
    int x, y;
};

struct point {
    int x, y;
    vec operator < (point other) const {
        return {x - other.x, y - other.y};
    }
};

struct rectangle {
    point ll, ur;
    friend ostream& operator<<(ostream& os, const rectangle& r);
    friend istream& operator>>(istream& is, rectangle& r);
};

ostream& operator<<(ostream& os, const rectangle& r) {
    os << r.ll.x << " " << r.ll.y << " " << r.ur.x << " " << r.ur.y;
    return os;
}

istream& operator>>(istream& is, rectangle& r) {
    is >> r.ll.x >> r.ll.y >> r.ur.x >> r.ur.y;
    return is;
}

bool intersect(rectangle a, rectangle b) {
    if(b.ll.x - a.ll.x >= a.ur.x - a.ll.x) return false;
    if(b.ll.y >= a.ur.y || b.ur.y <= a.ll.y) return false;
    return true;
}

rectangle intersection(rectangle a, rectangle b) {
    rectangle r;
    r.ll.x = b.ll.x;
    r.ur.x = min(a.ur.x, b.ur.x);
    if(b.ll.y >= a.ll.y && b.ur.y <= a.ur.y) {
        r.ll.y = b.ll.y;
        r.ur.y = b.ur.y;
    }
    else if(b.ll.y >= a.ll.y) {
        r.ll.y = b.ll.y;
        r.ur.y = a.ur.y;
    }
    else {
        r.ll.y = a.ll.y;
        r.ur.y = b.ur.y;
    }
    return r;
}

int main() {
    int TC;
    cin >> TC;
    for(int i = 0; i < TC; ++i) {
        string res;
        rectangle a, b;
        cin >> a >> b;
        if(a.ll.x > b.ll.x) swap(a, b);
        if(i) cout << endl;
        if(intersect(a, b)) cout << intersection(a, b);
        else cout << "No Overlap";
        cout << endl;
    }
}