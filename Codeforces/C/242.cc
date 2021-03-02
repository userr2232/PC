#include <map>
#include <iostream>
#include <queue>
#include <utility>
#include <set>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
typedef pair<int,int> ii;

vector<int> dr;
vector<int> dc;
map<ii, int> mm;
map<ii, int> marked;

int BFS(ii p1, ii p2) {
    auto [r2, c2] = p2;
    queue<ii> q;
    q.push(p1);
    marked[p1]++;
    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        for(int i = 0; i < 8; ++i) {
            int r{p.first + dr[i]}, c{p.second + dc[i]};
            if(r >= 1 && r <= 1e9 && c >= 1 && c <= 1e9 && mm[{r, c}] && !marked[{r, c}]) {
                if(r == r2 && c == c2) return marked[p];
                q.push({r, c});
                marked[{r, c}] = marked[p] + 1;
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r0, c0, r1, c1, n, r, a, b;
    cin >> r0 >> c0 >> r1 >> c1;
    cin >> n;
    ii zero = {0, 0};
    for(int i = -1; i <= 1; ++i) {
        for(int j = -1; j <= 1; ++j) {
            ii p = {i, j};
            if(p != zero) {
                dr.push_back(i);
                dc.push_back(j);
            }
        }
    }
    while(n--) {
        cin >> r >> a >> b;
        for(int i = a; i <= b; ++i)
            mm[{r, i}]++;
    }
    cout << BFS({r0, c0}, {r1, c1}) << endl;
}