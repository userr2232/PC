#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    long double answer{0};
    while(n) answer += 1.0L / n--;
    cout << answer << endl;
    return 0;
}