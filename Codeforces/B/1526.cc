#include <iostream>
#include <vector>
using namespace std;
typedef vector<bool> vi;

int main() {
    int TC; cin >> TC;
    while(TC--) {
        int x; cin >> x;
        bool b = false;
        for(int i = 0; i <= 10 && x >= i*111; ++i) {
            if((x - i*111)%11 == 0) b = true;
        }
        cout << (b ? "YES" : "NO") << endl;
    }
}