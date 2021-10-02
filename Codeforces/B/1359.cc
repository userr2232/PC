#include <iostream>
#include <string>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;

int main() {
    int TC; cin >> TC;
    while(TC--) {
        int n, m, x, y; cin >> n >> m >> x >> y;
        int cost{0};
        FOR(i,1,n) {
            string str; cin >> str;
            int white{0};
            FOR(j,0,m-1) {
                char c = str[j];
                if(c == '.') white++;
                if(c == '*' || j == m-1) {
                    if(y < 2*x) {
                        cost += y * (white / 2);
                        white %= 2;
                        cost += white ? x : 0;
                    }
                    else {
                        cost += x * white;
                    }
                    white = 0;
                }
            }
        }
        cout << cost << endl;
    }
}