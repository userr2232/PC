#include <iostream>

using namespace std;

int a, x, y;

bool on_border() {
    if(y % a == 0) return true;
    if(y < 2*a) {
        if(x == a/2.0 || x == -a/2.0) return true;
        return false;
    }
    int yp = y - 2*a;
    if((yp / a) % 2) {
        if(x == a/2.0 || x == -a/2.0) return true;
        return false;
    }
    else {
        if(x == a || x == -a || x == 0) return true;
        return false;
    }
    return false; // does not reach this point
}

bool outside() {
    if(y < 0) return true;
    else if(y == 0) return false;
    if(y < 2*a) {
        if(x > a/2.0 || x < -a/2.0) return true;
        return false;
    }
    else {
        int yp = y - 2*a;
        if((yp / a) % 2) {
            if(x > a/2.0 || x < -a/2.0) return true;
            return false;
        }
        else {
            if(x > a || x < -a) return true;
            return false;
        }
    }
    return false; // does not reach this point
}

int sq() {
    if(y < 2*a) return (y / a) + 1;
    else {
        int yp = y-2*a;
        if((yp/a)%2) return 3 * ((yp/a + 1) / 2) + 2;
        else {
            int prev = 3 * (yp/a / 2) + 2;
            if(x > 0) return prev + 2;
            return prev + 1;
        }
    }
    return -1;
}

int main() {
    cin >> a >> x >> y;
    if(outside() || on_border()) cout << -1 << endl;
    else cout << sq() << endl;
    return 0;
}