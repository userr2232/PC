#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k, z;
        cin >> n >> k >> z;
        vector<int> v(n);
        for(int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        int max_pair_sum = 0;
        int max_pos = 0;
        for(int i = 0; i < k; ++i) {
            if(max_pair_sum < v[i] + v[i+1]) {
                max_pair_sum = v[i] + v[i+1];
                max_pos = i+1;
            }
        }
        int cur = 0;
        int score = v[cur];
        while(k--) {
            if(cur == max_pos && z) {
                z--;
                cur--;
            }
            else {
                cur++;
            }
            score += v[cur];
        }
        cout << score << endl;
    }
}