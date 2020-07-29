#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, cur, tmp, count(0);
    cin >> n;
    cur = n;
    set<int> s;
    while(cur != 0) {
        if(count < n) {
            cin >> tmp;
            s.insert(tmp);
            count++;
        }
        if(s.count(cur)) {
            while(s.count(cur)) {
                cout << cur << " ";
                cur--;
            }
            cout << endl;
        }
        else {
            cout << endl;
        }
    }

    return 0;
}