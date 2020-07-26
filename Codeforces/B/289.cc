#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, d;
    const int N = 10001;
    cin >> n >> m >> d;
    n *= m;
    vector<int> v(N + 1, 0);
    int min = 1e9;
    int dif = 0;
    for(int i = 1; i <= n; ++i) {
        int tmp;
        cin >> tmp;
        if(v[tmp] == 0) dif++;
        v[tmp]++;
    }
    int min_moves = 1e9;
    int cant_count = 0;
    for(int i = 1; i <= N; ++i) {
        if(!v[i]) continue;
        int moves = 0;
        bool can = true;
        for(int j = 1; j <= N; ++j) {
            int tmp = j - i;
            if(!v[j]) continue;
            tmp = tmp < 0 ? -tmp : tmp;
            if(tmp % d == 0)
                moves += v[j] * tmp / d;
            else 
                can = false;
        }
        if(can) {
            min_moves = moves < min_moves ? moves : min_moves;
        }
        else {
            cant_count++;
        }
    }
    if(cant_count == dif)
        cout << -1 << endl;
    else
        cout << min_moves << endl;
    return 0;
}