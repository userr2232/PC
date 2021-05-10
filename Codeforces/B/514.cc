#include <iostream>
#include <set>
#include <utility>

using namespace std;

int main() {
    int n, x0, y0, x, y;
    cin >> n >> x0 >> y0;
    set<double> s;
    for(int i = 0; i < n; ++i) {
        cin >> x >> y;
        if(x == x0) s.insert(1e6);
        else s.insert((y - y0) * 1.0 / (x - x0));
    }
    cout << s.size() << endl;
    return 0;
}