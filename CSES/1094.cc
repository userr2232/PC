#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, tmp, left{0}; cin >> n;
    long long answer{0};
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        answer += max(0, left - tmp);
        left = max(left, tmp);
    }
    cout << answer << endl;

    return 0;
}