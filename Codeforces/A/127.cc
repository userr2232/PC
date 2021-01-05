#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

double dist(Point a, Point b) {
    return hypot(a.x - b.x, a.y - b.y);
}

int main() {
    int n, k, x, y;
    double d{0};
    Point prevP;
    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        cin >> x >> y;
        auto p = Point{x, y};
        if(i)
            d += dist(prevP, p);
        prevP = p;
    }
    cout << fixed << setprecision(6) << d * k / 50.0 << endl;
}