#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>

using namespace std;

int main() {
    freopen ("input.txt","r",stdin);
    int n, tmp;
    cin >> n;
    map<int,int> mm;
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        mm[tmp]++;
    }
    fclose (stdin);
    int answer = 2e9;
    for(int c = 1; c <= 5000; ++c) {
        auto m1 = mm.lower_bound(c);
        auto m2 = mm.upper_bound(2*c);
        int s = 0;
        for(auto it = mm.begin(); it != m1; ++it) {
            s += it->second;
        }
        for(auto it = m2; it != mm.end(); ++it) {
            s += it->second;
        }
        answer = min(answer, s);
    }
    freopen ("output.txt","w",stdout);
    cout << answer << endl;
    fclose (stdout);

    return 0;
}