#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>

using namespace std;

vector<int> dr = {1, 0, 0, -1};
vector<int> dc = {0, 1, -1, 0};
set<pair<int,int>> unvisited;
int n, m, x, y;

int largest_cc_size = 0, current_cc_size = 0;

void DFS(pair<int,int> start) {
    auto [row, col] = start;
    unvisited.erase(start);
    for(int i = 0; i < 4; ++i) {
        pair<int,int> neighbor = {(row + dr[i]), (col + dc[i])};
        if(neighbor.second == m) neighbor.second = 0;
        if(neighbor.second == -1) neighbor.second = m-1;
        if(unvisited.count(neighbor)) {
            current_cc_size++;
            DFS(neighbor);
        }
    }
}

int main() {
    while(cin >> n >> m) {
        largest_cc_size = 0;
        current_cc_size = 0;
        vector<string> v(n);
        for(int i = 0; i < n; ++i)
            cin >> v[i];
        cin >> x >> y;
        char c = v[x][y];
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(v[i][j] == c)
                    unvisited.insert({i, j});
        DFS({x, y});
        while(!unvisited.empty()) {
            current_cc_size = 1;
            DFS(*unvisited.begin());
            largest_cc_size = max(largest_cc_size, current_cc_size);
        }
        cout << largest_cc_size << endl;
    }
    return 0;
}