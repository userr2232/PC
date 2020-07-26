#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        int evens(0), odds(0);
        for(int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            if(tmp % 2) odds++;
            else evens++;
        }
        if(x % 2 == 0 && evens == 0 || odds == 0 || x == n && odds % 2 == 0)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}