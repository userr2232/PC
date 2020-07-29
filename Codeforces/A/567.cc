#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int n, tmp;
    cin >> n;
    vector<pair<int,int>> v(n);
    vector<int> b(n);
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        v[i] = {tmp, i+1};
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; ++i) {
        b[v[i].second-1] = i;
    }

    for(int i = 0; i < n; ++i) {
        if(i == 0) {
            cout << v[b[1]].first - v[b[0]].first << " " << v[b[n-1]].first - v[b[0]].first << endl;
        }
        else  if(i == n-1) {
            cout << v[b[n-1]].first - v[b[n-2]].first << " " << v[b[n-1]].first - v[b[0]].first << endl;
        }
        else {
            cout << min(v[b[i]].first - v[b[i-1]].first, v[b[i+1]].first - v[b[i]].first) << " " 
                    << max(v[b[i]].first - v[b[0]].first, v[b[n-1]].first - v[b[i]].first) << endl;
        }
    }

    return 0;
}