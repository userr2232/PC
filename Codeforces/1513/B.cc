#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n, tmp;
        cin >> n;
        map<long long, long long> mm;
        for(long long i = 0 ; i < n; ++i) {
            cin >> tmp;
            mm[tmp]++;
        }
        long long answer{1};
        bool b = false;
        for(auto [k, v] : mm) {
            if(v > 1) {
                b = true;
                while(v) answer *= v-- % (long long)(1e9 + 7);
            }
        }
        if(!b) cout << 0 << endl;
        else {
            n -= 2;
            while(n) answer *= n-- % (long long)(1e9 + 7);
            cout << answer << endl;
        }
    }

    return 0;
}