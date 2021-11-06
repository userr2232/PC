#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2e9
using namespace std;
typedef vector<int> vi;

class SegmentTree {
private:
    vi lo, hi, delta, min_;
public:
    SegmentTree(int n) {
        lo = hi = delta = min_ = vi(4*n+1, 0);
        init(1, 0, n-1);
    }

    void init(int i, int a, int b) {
        lo[i] = a, hi[i] = b;
        if(a == b) return;
        int m = a + (b - a) / 2;
        init(2*i, a, m);
        init(2*i+1, m+1, b);
    }

    void increment(int a, int b, int val) {
        return increment(1, a, b, val);
    }

    void increment(int i, int a, int b, int val) {
        if(lo[i] > b || hi[i] < a) return;
        if(lo[i] <= a && hi[i] >= b) { delta[i] += val; return; }
        prop(i);
        increment(2*i, a, b, val);
        increment(2*i+1, a, b, val);
        update(i);
    }

    void prop(int i) {
        delta[2*i] += delta[i];
        delta[2*i+1] += delta[i];
        delta[i] = 0;
    }

    void update(int i) {
        min_[i] = min(min_[2*i]+delta[2*i], min_[2*i+1]+delta[2*i+1]);
    }

    int RMQ(int a, int b) {
        return minimum(1, a, b);
    }

    int minimum(int i, int a, int b) {
        if(lo[i] > b || hi[i] < a) return INF;
        if(lo[i] <= a && hi[i] >= b) return min_[i] + delta[i];
        prop(i);
        int min_left = minimum(2*i, a, b);
        int min_right = minimum(2*i+1, a, b);
        update(i);
        return min(min_left, min_right);
    }
};