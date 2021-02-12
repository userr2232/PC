#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        int count{0};
        for(int i = 1; i <= t; ++i) {
            int k = sqrt(i);
            if(k * k == i) ++count;
        }
        cout << count << endl;
    }
}