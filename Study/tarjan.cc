#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define UNVISITED 0
#define VISITED 1
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vii> AdjList;
AdjList graph;
vi dfs_low, dfs_num, S;
vector<bool> visited;
int dfsNumberCounter, numSCC;

void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    S.emplace_back(u);
    visited[u] = true;
    FOR(j,0,graph[u].size()-1) {
        auto [v, w] = graph[u][j];
        if(dfs_num[v] == UNVISITED) tarjanSCC(v);
        if(visited[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if(dfs_low[u] == dfs_num[u]) {
        printf("SCC %d:", ++numSCC);
        while(true) {
            int v = S.back(); S.pop_back(); visited[v] = false;
            printf(" %d", v);
            if(u == v) break;
        }
        cout << endl;
    }
}

int main() {
    int V, E; cin >> V >> E;
    int u, v;
    graph.resize(V+1);
    FOR(i,1,E) cin >> u >> v, graph[u].emplace_back(v), graph[v].emplace_back(u);
    dfs_num.assign(V+1, UNVISITED);
    dfs_low.assign(V+1, 0);
    visited.assign(V+1, false);
    FOR(i,1,V) if(dfs_num[i] == UNVISITED) tarjanSCC(i);
}