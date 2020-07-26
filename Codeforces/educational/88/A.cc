#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int max_j = min(n / k, m);
        m -= max_j;
        n -= m;
        k--;
        int second_max_j = ceil(m * 1.0/ k);
        cout << max_j - second_max_j << endl;
    }
    return 0;
}