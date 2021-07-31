#include <iostream>
#include <vector>
#define UNVISITED 0
#define VISITED 1
using namespace std;
typedef vector<int> vi;

vi dfs_num, ts;

void df2(int u) {
    dfs_num[u] = VISITED;
    for(int j = 0; j < AdjList[u].size(); ++j) {
        auto [v, _] AdjList[u][j];
        if(dfs_num[v] == UNVISITED) df2(v);
    }
    ts.emplace_back(u);
}

int main() {
    ts.clear();
    memset(dfs_num, UNVISITED, sizeof dfs_num);
    for(int i = 0; i < V; ++i) if(dfs_num[i] == UNVISITED) dfs(i);
    for(int i = ts.size()-1; i >= 0; --i) cout << ts[i] << " ";
    cout << endl;
}