#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n, m, c;
    while(cin >> n >> m >> c, n + m + c) {
        int whiterows, blackrows;
        whiterows = n >= 8 ? (n - 8) / 2 + 1 : 0;
        n--;
        blackrows = n >= 8 ? (n - 8) / 2 + 1 : 0;
        if(!c)
            swap(whiterows, blackrows);
        int res = m >= 8 ? ((m - 8) / 2 + 1) * whiterows : 0;
        m--;
        res += m >= 8 ? ((m - 8) / 2 + 1) * blackrows : 0;
        cout << res << endl;
    }

    return 0;
}