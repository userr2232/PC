#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int main() {
    int n, tmp;
    cin >> n;
    set<int> s;
    multiset<int> ms;
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        s.insert(tmp);
        ms.insert(tmp);
    }
    bool b = true;
    if(n > 1)
        for(auto x : s) {
            if(ms.count(x) > ceil(ms.size() * 1.0 / 2)) {
                b = false;
                break;
            }
        }
    cout << (b ? "YES" : "NO") << endl;
}