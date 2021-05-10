#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n; cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    int answer{0};
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < n; ++k) {
                if(v[i][j] == 'C') {
                    if(k != j && v[i][k] == v[i][j]) answer++;
                    if(k != i && v[k][j] == v[i][j]) answer++;
                }
            }
        }
    }
    cout << answer / 2 << endl;
    return 0;
}