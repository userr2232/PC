#include <iostream>
#include <set>
#include <iterator>

using namespace std;

int main() {
    int n, t;
    set<int> as;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> t;
        as.insert(t);
        if(as.size() > 3) {
            cout << "NO" << endl;
            return 0;
        }
    }
    auto begin = as.begin();
    if(as.size() == 3 && 2 * *next(begin) - *(begin) != *(next(next(begin))))
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}