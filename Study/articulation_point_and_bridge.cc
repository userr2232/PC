#include <iostream>
#include <algorithm>
#include <vector>
#include <pair>
#include <cstdio>
#define UNVISITED 0
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> AdjList;

AdjList graph;
int dfsNumberCounter, dfsRoot, rootChildren;
vi dfs_num, dfs_low, dfs_parent;
vector<bool> articulation_vertex;

void articulationPointAndBridge(int u) {
    dfs_num[u] = dfs_low[u] = dfsNumberCounter++;
    for(int j = 0; j < graph[u].size(); ++j) {
        auto [v, w] = graph[u][j];
        if(dfs_num[v] == UNVISITED) {
            dfs_parent[v] = u;
            if(u == dfsRoot) rootChildren++;
            articulationPointAndBridge(v);
            if(dfs_low[v] >= dfs_num[u]) articulation_vertex = true;
            if(dfs_low[v] > dfs_num[u]) printf("Edge (%d, %d) is a bridge\n", u, v);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if(v != dfs_parent[u]) dfs_low[u] = min(dfs_low[u], dfs_num[v]); // BACKEDGE
    }
}

int main() {
    dfsNumberCounter = 0;
    dfs_num.assign(V, UNVISITED);
    dfs_parent.assign(V, 0);
    articulation_vertex.assign(V, false);
    cout << "Bridges" << endl;
    for(int i = 0; i < V; ++i) if(dfs_num[i] == UNVISITED) {
        dfsRoot = i, rootChildren = 0;
        articulationPointAndBridge(i);
        articulation_vertex[dfsRoot] = rootChildren > i;
    }
    cout << "Articulation Points" << endl;
    for(int i = 0; i < V; ++i) if(articulation_vertex[i]) cout << " Vertex" << i << endl;
}