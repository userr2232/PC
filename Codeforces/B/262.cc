#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, k, a, last;
    bool b = false;
    cin >> n >> k;
    int s{0};
    for(int i = 0; i < n; ++i) {
        cin >> a;
        if(k > 0) {
            if(a < 0) {
                if(i == n-1) {
                    if(k % 2 == 0) s += a;
                    else s -= a;
                    k = 0;
                }
                else {
                    k--;
                    s += -a;
                }
            }
            else if(a == 0) {
                k = 0;
            }
            else {
                if(k % 2 == 0) {
                    s += a;
                }
                else {
                    if(b) {
                        if(abs(last) < a) {
                            s -= -last;
                            s += last;
                            s += a;
                        }
                        else {
                            s -= a;
                        }
                    }
                    else s -= a;
                }
                k = 0;
            }
        }
        else {
            s += a;
        }
        b = true;
        last = a;
    }
    cout << s << endl;

    return 0;
}