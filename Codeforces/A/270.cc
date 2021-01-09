#include <iostream>
#include <cmath>

#define M_PI 3.141592653589793238462643383279502884197169399375105820974944592307816406
#define DEG_TO_RAD (M_PI/180.0)
#define EPS 1e-9

using namespace std;

struct vec {
    double x, y;
    vec& operator+=(const vec& rhs){
      this->x += rhs.x;
      this->y += rhs.y;
      return *this;
    }
};

vec rotate(vec v, double theta) {
    double rad = DEG_TO_RAD * theta;
    return {v.x * cos(rad) - v.y * sin(rad),
                v.x * sin(rad) + v.y * cos(rad)};
}

void reg_polygon(double theta) {
    vec v{1, 0}, rot{1, 0};
    for(int i = 0; i < 500; ++i) {
        rot = rotate(rot, 180 - theta);
        v += rot;
        if(v.y < -EPS) break; // convex
        if(abs(v.x) < EPS && abs(v.y) < EPS) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main () {
    int n;
    cin >> n;
    while(n--) {
        int t;
        cin >> t;
        reg_polygon(t);
    }
}