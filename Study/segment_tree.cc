#include <iostream>
#include <algorithm>
#include <vector>
#define INF 2e9
using namespace std;
typedef vector<int> vi;

class SegmentTree {
private:
    int n;
    vi lo, hi, min, delta;
public:
    SegmentTree(int n): n{n} {
        lo = hi = min = delta = vi(4*n+1,0);
        init(1, 0, n-1);
    }

    void init(int i, int a, int b) {
        lo[i] = a, hi[i] = b;
        if(a == b) return;
        int m = (a+b) / 2;
        init(2*i, a, m);
        init(2*i+1, m+1, b);
    }

    void increment(int a, int b, int val) {
        return increment(1, a, b, val);
    }

    void increment(int i, int a, int b, int val) {
        if(a > hi[i] || b < lo[i]) return;
        if(a <= lo[i] && b >= hi[i]) { delta[i] += val; return; }
        prop(i);
        increment(2*i, a, b, val);
        increment(2*i, a, b, val);
        update(i);
    }

    void update(int i) {
        min[i] = min(min[2*i]+delta[2*i], min[2*i+1]+delta[2*i+1]);
    }

    void prop(int i) {
        delta[2*i] += delta[i];
        delta[2*i] += delta[i];
        delta[i] = 0;
    }

    int minimum(int a, int b) {
        return minimum(1, a, b);
    }

    int minimum(int i, int a, int b) {
        if(a > hi[i] || b < lo[i]) return INF;
        if(a <= lo[i] && b >= hi[i]) return min[i] + delta[i];
        prop(i);
        int minLeft = minimum(2*i, a, b);
        int minRight = minimum(2*i, a, b);
        update(i);
        return min(minLeft, minRight);
    }
};