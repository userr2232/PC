#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdio>
#define UNVISITED 0
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> AdjList;
AdjList graph;
vi dfs_num, dfs_low, dfs_parent;
vector<bool> articulation_vertex;
int dfsNumberCounter, rootChildren, dfsRoot;

void articulationPointAndBridge(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    for(int j = 0; j < graph[u].size(); ++j) {
        auto [v, w] = graph[u][j];
        if(dfs_num[v] == UNVISITED) {
            dfs_parent[v] = u;
            if(u == dfsRoot) rootChildren++;
            articulationPointAndBridge(v);
            if(dfs_low[v] >= dfs_num[u]) articulation_vertex[u] = true;
            if(dfs_low[v] > dfs_num[u]) printf(" Edge (%d, %d) is a bridge\n", u, v);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if(v != dfs_parent[u]) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main() {
    int V, E; cin >> V >> E;
    graph.resize(V+1);
    int u, v;
    FOR(i,1,E) cin >> u >> v, graph[u].emplace_back(v), graph[v].emplace_back(u);
    dfs_num.assign(V+1, UNVISITED);
    dfs_low.assign(V+1, 0);
    dfs_parent.assign(V+1, 0);
    articulation_vertex(V+1, false);
    cout << "Bridges:" << endl;
    FOR(i,1,V) if(dfs_num[i] == UNVISITED) {
        dfsRoot = i, dfsNumberCounter = 0, dfsChildren = 0;
        articulationPointAndBridge(dfsRoot);
        articulation_vertex[dfsRoot] = rootChildren > 1;
    }
    cout << "Articulation Points:" << endl;
    FOR(i,0,V-1) if(articulation_vertex[i]) cout << " Vertex " << i << endl;
}