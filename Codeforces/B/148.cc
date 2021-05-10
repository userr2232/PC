#include <iostream>

using namespace std;

int main() {
    int vp, vd, t, f, c;
    cin >> vp >> vd >> t >> f >> c;
    int answer{0};
    long double pd{0}, pp{(long double)t*vp};
    while(vp < vd && pp < c) {
        // chasing
        long double tto = pp / (vd - vp);
        pd = tto * vd;
        pp += tto * vp;
        if(pp >= c) break;
        ++answer;
        // not chasing
        long double ttc = pd / vd;
        pp += (ttc + f) * vp;
    }
    cout << answer << endl;
    return 0;
}