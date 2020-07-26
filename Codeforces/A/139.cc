#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(7);
    int sum = 0;
    int last = 0;
    for(int i = 0; i < 7; ++i) {
        cin >> v[i];
        if(v[i]) last = i;
        sum += v[i];
    }
    n = n % sum;
    if(n == 0)
        cout << last + 1 << endl;
    else
        for(int i = 0; i < 7; ++i) {
            n -= v[i];
            if(n <= 0) {
                cout << i + 1 << endl;
                return 0;
            }
        }
    return 0;
}