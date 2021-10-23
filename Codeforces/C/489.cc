#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;
typedef vector<int> vi;

bool can(int m, int s) {
    return s >= 0 && s <= m * 9;
}

int main() {
    int m, s; cin >> m >> s;
    string mn, mx;
    int sum1, sum2;
    sum1 = sum2 = s;
    for(int i = 0; i < m; ++i) {
        for(int d = 0; d < 10; ++d) 
            if((i > 0 || d > 0 || (m == 1 && d == 0)) && can(m-i-1, sum1-d) && (i == 0 || (i > 0 && mn != ""))) {
                mn += char('0' + d);
                sum1 -= d;
                break;
            }
        for(int d = 9; d >= 0; --d)
            if((i > 0 || d > 0 || (m == 1 && d == 0)) && can(m-i-1, sum2-d) && (i == 0 || (i > 0 && mx != ""))) {
                mx += char('0' + d);
                sum2 -= d;
                break;
            }
    }
    cout << (mn == "" ? "-1" : mn) << " ";
    cout << (mx == "" ? "-1" : mx) << endl;
}