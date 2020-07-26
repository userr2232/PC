#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        const int N = 1024;
        vector<bool> v(N + 1, false);
        vector<int> values(n);
        int sum = (N << 1) -1;
        for(int i = 0; i < n; ++i) {
            cin >> values[i];
            v[values[i]] = true;
        }
        for(int k = 1; k <= sum; ++k) {
            int count = 0;
            for(auto const& x: values) {
                if((k ^ x) <= N && v[k ^ x]) count++;
            }
            if(count == values.size()) {
                cout << k << endl;
                break;
            }
            else if(k == sum)
                cout << -1 << endl;
        }
    }
    return 0;
}