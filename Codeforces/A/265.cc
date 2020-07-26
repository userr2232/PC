#include <iostream>

using namespace std;

int main() {
    string a;
    cin >> a;
    string b;
    cin >> b;
    int cur = 0;
    for(auto const& c: b) {
        if(c == a[cur]) {
            cur++;
        }
    }
    cout << ++cur << endl;

    return 0;
}