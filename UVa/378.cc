#include <iostream>
#include <complex>
#include <iomanip>
#include <cmath>

#define x real()
#define y imag()
#define dp(a, b) ((conj(a) * (b)).x)
#define cp(a, b) ((conj(a) * (b)).y)
#define EPS (1e-10)

using namespace std;

typedef complex<double> point;

double x_1, y_1, x_2, y_2, x_3, y_3, x_4, y_4;

bool isPointOnLine(point p1, point p2, point p3) {
    return abs(cp(p2-p1, p3-p2)) < EPS;
}

void solve() {
    cin >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3 >> x_4 >> y_4;
    point p1(x_1, y_1), p2(x_2, y_2), p3(x_3, y_3), p4(x_4, y_4);
    point v(p2 - p1), u(p4 - p3);
    if(abs(cp(v, u)) < EPS) {
        if(isPointOnLine(p1, p2, p3)) {
            cout << "LINE" << endl;
            return;
        }
        cout << "NONE" << endl;
        return;
    }
    cout << "POINT ";
    cout << fixed << setprecision(2);
    if(x_1 == x_2 || x_3 == x_4) {
        double m, b;
        if(x_1 == x_2) {
            m = u.y / u.x;
            b = y_3 - m * x_3;
            cout << x_1 << " " << m * x_1 + b << endl;
            return;
        }
        m = v.y / v.x;
        b = y_2 - m * x_2;
        cout << x_3 << " " << m * x_3 + b << endl;
        return;
    }
    double m1, b1, m2, b2, x0;
    m1 = v.y / v.x;
    m2 = u.y / u.x;
    b1 = y_2 - m1 * x_2;
    b2 = y_3 - m2 * x_3;
    x0 = (b2 - b1) / (m1 - m2);
    cout << x0 << " " << m1 * x0 + b1 << endl;
}


int main() {
    int t;
    cin >> t;
    cout << "INTERSECTING LINES OUTPUT" << endl;
    while(t--){
        solve();
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}