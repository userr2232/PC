#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i = 0 ; i < t; ++i) {
        int n;
        cin >> n;
        vector<int> b(n+2);
        long long sum{0};
        for(int j = 0; j < n+2; ++j) {
            cin >> b[j];
            sum += b[j];
        }
        int max_bj = 0, second_max_bj = 0;
        for(int j = 0; j < n+2; ++j) {
            if(b[max_bj] < b[j]) {
                second_max_bj = max_bj;
                max_bj = j;
            }
        }
        for(int j = 0; j < n+2; ++j) {
            bool b = false;
            for(int k = 0; k < n+2; ++k) {
                if(k == j || max_bj == j || max_bj == k) continue;
                if(b[max_bj] == sum - b[j] - b[k]) {
                    
                }
            }
        }
    }

    return 0;
}