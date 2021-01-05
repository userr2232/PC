#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double EPS = 1e-9;

struct point {
    double x, y;
    bool operator == (point other) const {
        return abs(x - other.x) < EPS && abs(y - other.y) < EPS;
    }
};

struct rectangle {
    point top_left, bottom_right;
    rectangle(double x0, double y0, double x1, double y1): top_left{x0, y0}, bottom_right{x1, y1} {}
};

bool is_contained(point p, rectangle r) {
    return p.y < r.top_left.y && p.y > r.bottom_right.y && p.x > r.top_left.x && p.x < r.bottom_right.x;
}

int main() {
    char figure;
    double x0, y0, x1, y1;
    vector<rectangle> rectangles;
    while(cin >> figure, figure != '*') {
        cin >> x0 >> y0 >> x1 >> y1;
        rectangles.push_back({x0, y0, x1, y1});
    }
    double x, y;
    point e{9999.9, 9999.9};
    int i = 1;
    while(cin >> x && cin >> y) {
        bool contained = false;
        point p{x, y};
        if(p == e) break;
        for(int j = 0; j < rectangles.size(); ++j) {
            if(is_contained(p, rectangles[j])) {
                cout << "Point " << i << " is contained in figure " << j + 1 << endl;
                contained = true;
            }
        }
        if(!contained)
            cout << "Point " << i << " is not contained in any figure" << endl;
        ++i;
    }
}