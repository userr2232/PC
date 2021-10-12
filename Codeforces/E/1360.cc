#include <iostream>
#include <vector>
using namespace std;

int main() {
    int TC; cin >> TC;
    while(TC--) {
        int n; cin >> n;
        vector<string> M(n);
        for(auto& str : M) cin >> str;
        bool NO = false;
        for(int i = 0; i < n && !NO; ++i) for(int j = 0; j < n && !NO; ++j) {
            char c = M[i][j];
            if(c == '1') {
                if(i == n-1 || j == n-1) continue;
                if(i < n-1 && M[i+1][j] == '1') continue;
                if(j < n-1 && M[i][j+1] == '1') continue;
                cout << "NO\n";
                NO = true;
            }
        }
        if(!NO) cout << "YES\n";
    }
    return 0;
}