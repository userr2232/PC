#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(const vector<string>& v) {
    for(const auto& s : v) {
        cout << s << endl;
    }
}

int main() {
    int n, k; cin >> n >> k;
    vector<string> v(n, string(n, 'S'));
    for(int i = 0; i < n; ++i) {
        int start = (i % 2);
        for(int j = start; j < n; j+=2) {
            if(k-- == 0) {
                cout << "YES" << endl;
                print(v);
                return 0;
            }
            v[i][j] = 'L';
        }
    }
    if(k) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        print(v);
    }
    return 0;
}