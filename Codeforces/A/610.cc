#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int answer{0};
    for(int i = 1; i <= n/4; ++i) {
        if((n-2*i)%2 == 0 && i != (n-2*i)/2) {
            answer++;
        }
    }
    cout << answer << endl;
    return 0;
}