#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int TC; cin >> TC;
    while(TC--) {
        int n, H; cin >> n >> H;
        int max_a{0}, second_max_a{0};
        for(int i = 0; i < n; ++i) {
            int x; cin >> x;
            if(x > max_a) {
                second_max_a = max_a;
                max_a = x;
            }
            else second_max_a = max(second_max_a, x);
        }
        int k = H / (max_a + second_max_a);
        H -= k * (max_a + second_max_a);
        k *= 2;
        if(H > max_a) k += 2;
        else if(H) ++k;
        cout << k << endl;
    }
}