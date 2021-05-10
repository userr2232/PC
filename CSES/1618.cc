#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int twos{0}, fives{0};
    int tmp = n/2;
    while(tmp) twos += tmp, tmp /= 2;
    tmp = n/5;
    while(tmp) fives += tmp, tmp /= 5;
    cout << min(twos, fives) << endl;
    return 0;
}