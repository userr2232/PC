#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int MAXN = 1000001;
    vector<long long> d(MAXN);
    for(int i = 1; i < MAXN; ++i)
        for(int j = i; j < MAXN; j += i)
            d[j]++;

    int a, b, c;
    cin >> a >> b >> c;
    long long answer {0};
    for(int i = 1; i <= a; ++i) {
        for(int j = 1; j <= b; ++j) {
            for(int k = 1; k <= c; ++k) {
                answer += d[i * j * k] % (2 << 30);
            }
        }
    }
    cout << answer << endl;
    return 0;
}