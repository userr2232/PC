#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, answer{0};
    cin >> n >> m;
    vector<int> owe(n, 0);
    int a, b, c;
    for(int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        owe[a-1] += c;
        owe[b-1] -= c;
    }
    for(auto x : owe) if(x > 0) answer += x;
    cout << answer << endl;

    return 0;
}