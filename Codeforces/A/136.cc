#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, tmp;
    cin >> n;
    vector<int> b(n);
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        b[tmp-1] = i + 1;
    }
    for(auto x : b) {
        cout << x << " ";
    }
    cout << endl;
}