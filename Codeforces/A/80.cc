#include <iostream>
#include <vector>

using namespace std;

void build(vector<int>& sieve) {
    int n = sieve.size() - 1;
    for(int x = 2; x <= n; ++x) {
        if(sieve[x]) continue;
        for(int k = x * 2; k <= n; k += x) {
            sieve[k] = x;
        }
    }
}

int main() {
    vector<int> v(50 + 1, 0);
    build(v);
    int n, m;
    cin >> n >> m;
    if(v[m])
        cout << "NO" << endl;
    else {
        for(int i = n + 1; i < m; ++i)
            if(!v[i]) {
                cout << "NO" << endl;
                return 0;
            }
        cout << "YES" << endl;
    }
    return 0;
}