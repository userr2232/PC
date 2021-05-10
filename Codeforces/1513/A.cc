#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        if(n < 2*k+1) {
            cout << -1 << endl;
            continue;
        }
        else {
            vector<int> v(n, -1);
            set<int> s;
            for(int i = 1; i <= n; ++i) {
                s.insert(i);
            }
            for(int i = 1; k-- && i < n-1; i+=2) {
                v[i] = i+2;
                s.erase(i+2);
            }
            for(int i = 0; i < n; ++i)  {
                auto it = s.begin();
                if(v[i] == -1) {
                    v[i] = *it;
                    s.erase(it);
                }
            }
            for(int i = 0; i < n; ++i) {
                cout << v[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}