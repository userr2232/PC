#include <iostream>
#include <vector>
using namespace std;

int main() {
    int TC; cin >> TC;
    while(TC--) {
        int n; cin >> n;
        vector<bool> prince_married(n, false), princess_married(n, false);
        for(int i = 0; i < n; ++i) {
            int k; cin >> k;
            for(int j = 0; j < k; ++j) {
                int x; cin >> x; x--;
                if(!prince_married[x] && !princess_married[i]) {
                    prince_married[x] = true;
                    princess_married[i] = true;
                }
            }
        }
        bool b = false;
        for(int i = 0; i < n; ++i) if(!princess_married[i]) {
            for(int j = 0; j < n; ++j) if(!prince_married[j]) {
                cout << "IMPROVE\n" << i+1 << " " << j+1 << endl;
                b = true;
                break;
            }
            if(b) break;
        }
        if(!b) cout << "OPTIMAL" << endl;
    }
    return 0;
}