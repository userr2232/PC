#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        int cost = 0;
        for(int i = 0; i < n; ++i) {
            char last = '*';
            for(int j = 0; j < m; ++j) {
                char tmp;
                cin >> tmp;
                if(tmp == '.') {
                    if(last == '.' && y < 2*x) {
                        cost -= x;
                        cost += y;
                        last = '*';
                    }
                    else {
                        last = '.';
                        cost += x;
                    }
                }
                else {
                    last = '*';
                }
            }
        }
        cout << cost << endl;
    }
    return 0;
}