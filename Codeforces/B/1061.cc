#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    bool counted = false;
    long long sum{0};
    long long fixed{0};
    vector<int> v(n,0);
    for(auto& x : v) cin >> x, sum += x;
    sort(v.begin(), v.end());
    for(int i = n-1; i > 0; --i) {
        if(v[i] < v[i-1]) v[i-1] = v[i];
        if(v[i] == v[i-1]) {
            fixed++;
            if(v[i-1] > 1) v[i-1]--;
        }
        else {
            fixed += v[i]-v[i-1];
        }
    }
    cout << sum - fixed - v[0] << endl;
}