#include <iostream>
#include <vector>

using namespace std;

vector<int> potency;
vector<int> weights;

bool are_neighbors(int a, int b) {
    int x = a ^ b;
    return (x & (-x)) == x;
}

int greatestPotencySum(int n) {
    int ans(0);
    for(int i = 0; i < 1 << n; ++i)
        for(int j = 0; j < 1 << n; ++j)
            ans = max(ans, are_neighbors(i,j) && i != j ? potency[i] + potency[j] : ans);
    return ans;
}

int main() {
    int n, w;
    while(cin >> n) {
        potency.clear(); weights.clear();
        potency.resize(1 << n); weights.resize(1 << n);
        for(int i = 0; i < 1 << n; ++i) {
            cin >> w;
            for(int j = 0; j < 1 << n; ++j)
                potency[j] += are_neighbors(i,j) && i != j ? w : 0;
        }
        cout << greatestPotencySum(n) << endl;
    }
    return 0;
}