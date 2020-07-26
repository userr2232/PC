#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        int mincost = str.size();
        int ones(0), zeros(0);
        for(char c : str) {
            if(c == '1') ones++;
            else zeros++;
        }
        int o(0), z(0);
        int cost;
        for(char c : str) {
            if(c == '1') o++;
            else z++;
            cost = ones - o + z;
            if(cost < mincost) mincost = cost;
            cost = o + zeros - z;
            if(cost < mincost) mincost = cost;
        }
        cout << mincost << endl;
    }

    return 0;
}