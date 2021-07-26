#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    for(auto c : s) if(c >= '0' && c <= '9') cout << c; else cout << " " << c << " ";
}