#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define UNVISITED -1
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> AdjList;

AdjList graph;
vi dfs_num, dfs_low, dfs_parent;
vector<bool> articulation_vertex;
int dfsRoot, rootChildren, dfsNumberCounter;

void articulationPointAndBridge(int u) {
    dfs_num[u] = dfs_low[u] = dfsNumberCounter++;
    FOR(j,0,graph[u].size()-1) {
        auto [v, _] = graph[u][j];
        if(dfs_num[v] == UNVISITED) {
            if(u == dfsRoot) rootChildren++;
            dfs_parent[v] = u;
            articulationPointAndBridge(v);
            if(dfs_low[v] >= dfs_num[u]) articulation_vertex[u] = true;
            if(dfs_low[v] > dfs_num[u]) cout << "Edge " << u << "-" << v << " is a bridge.\n";
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if(v != dfs_parent[u]) dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

int main() {
    int V, E; cin >> V >> E;
    graph.resize(V);
    dfs_num.assign(V, UNVISITED);
    dfs_low.resize(V);
    dfs_parent.assign(V, -1);
    articulation_vertex.assign(V, false);
    FOR(i,1,E) {
        int u, v, w; cin >> u >> v >> w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    cout << "Bridges:\n";
    FOR(u,0,V-1) {
        if(dfs_num[u] == UNVISITED) {
            dfsRoot = u, rootChildren = 0;
            articulationPointAndBridge(dfsRoot);
            articulation_vertex[u] = rootChildren > 1;
        }
    }
    cout << "Articulation points:\n";
    FOR(u,0,V-1) if(articulation_vertex[u]) cout << u << endl;
}