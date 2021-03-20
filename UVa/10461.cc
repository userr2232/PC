#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

int main() {
    int v, e, c{1};
    while(cin >> v >> e, e || v) {
        int x, y;
        vector<long long> task_time(v + 1, 0);
        map<int,set<int>> ancestors;
        map<int,set<int>> descendants;
        for(int i = 1; i <= v; ++i)
            cin >> task_time[i];
        for(int i = 0; i < e; ++i) {
            cin >> x >> y;
            ancestors[x].insert(y);
            descendants[y].insert(x);
            for(auto a: ancestors[y]) {
                for(auto d : descendants[x]) {
                    descendants[a].insert(d);
                    descendants[a].insert(x);
                    descendants[y].insert(d);
                    ancestors[d].insert(a);
                    ancestors[x].insert(a);
                    ancestors[d].insert(y);
                }
            }
            for(auto d : descendants[x]) {
                ancestors[d].insert(y);
                descendants[y].insert(d);
            }
            for(auto a : ancestors[y]) {
                descendants[a].insert(x);
                ancestors[x].insert(a);
            }
        }
        int q;
        cin >> q;
        cout << "Case #" << c++ << ":" << endl;
        while(q--) {
            long long sum{0}, qn;
            cin >> qn;
            for(int i = 1; i <= v; ++i) {
                if(!ancestors[qn].count(i) && !descendants[qn].count(i) && i != qn) {
                    sum += task_time[i];
                    // cout << i << endl;
                }
            }
            cout << sum << endl;
            // if(qn == 90) return 0;
        }
        cout << endl;
    }
}