#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define UNVISITED -1
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> AdjList;

AdjList graph;
vi dfs_low, dfs_num, S;
vector<bool> visited;

int dfsNumberCounter, SCC;

void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = ++dfsNumberCounter;
    visited[u] = true;
    S.emplace_back(u);
    FOR(j,0,graph[u].size()-1) {
        auto [v, _] = graph[u][j];
        if(dfs_num[v] == UNVISITED) tarjanSCC(v);
        if(visited[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        if(dfs_num[u] == dfs_low[u]) {
            cout << "SCC: " << ++SCC << endl;
            while(true) {
                int v = S.back();
                S.pop_back();
                visited[v] = false;
                if(u == v) break;
            }
        }
    }
}

int main() {
    int V, E; cin >> V >> E;
    graph.resize(V);
    dfs_low.resize(V);
    dfs_num.assign(V, UNVISITED);
    visited.assign(V, false);
    FOR(i,1,E) {
        int u, v, w; cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    FOR(u,0,V-1) if(dfs_num[u] == UNVISITED) tarjanSCC(u);
}