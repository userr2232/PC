#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;

int n, l, r, x, ans{0};
int mn{(int)2e9}, mx{-1}, tot{0};
vector<int> v;

void search(int id = 0) {
    if(id == n) { if(mn != 2e9 && mx - mn >= x && tot >= l && tot <= r) ans++; return; }
    auto pmx = mx;
    auto pmn = mn;
    mx = max(mx, v[id]);
    mn = min(mn, v[id]);
    tot += v[id];
    search(id+1);
    mx = pmx;
    mn = pmn;
    tot -= v[id];
    search(id+1);
}

int main() {
    cin >> n >> l >> r >> x;
    v.resize(n);
    FOR(i,0,n-1) cin >> v[i];
    search();
    cout << ans;
    return 0;
}