#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cur = 0;
    int min_cap = 0;
    while(n--) {
        int a, b;
        cin >> a >> b;
        cur -= a;
        cur += b;
        if(cur > min_cap)
            min_cap = cur;
    }
    cout << min_cap << endl;
}