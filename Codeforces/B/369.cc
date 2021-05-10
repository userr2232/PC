#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, l, r, sall, sk; cin >> n >> k >> l >> r >> sall >> sk;
    vector<int> v(n, r);
    int skp = r * k;
    int left{k-1}, right{n-1};
    while(skp != sk) {
        while(skp != sk && left >= 0) --v[left--], --skp;
        if(left < 0) left = k-1;
    }
    for(int i = k; i < n ; ++i) {
        v[i] = v[k-1];
    }
    int rest = v[k-1] * (n-k);
    while(rest != sall - sk) {
        while(rest != sall - sk && right >= k) --v[right--], --rest;
        if(right < k) right = n-1;
    }
    for(int x : v) cout << x << " ";
    cout << endl;
}