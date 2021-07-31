#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;

int dfsNumberCounter{0};
vi dfs_num;

void articulatioonPointAndBridge(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
    for(int j = 0; j < AdjList[u].size(); ++j) {
        auto [v, _] = AdjList[u][j];
        if(dfs_num[v] == UNVISITED) {
            dfs_parent[v] = u;
            if(u == dfsRoot) rootChildren++;
            articulatioonPointAndBridge(v);
            if(dfs_low[v] >= dfs_num[u]) articulation_vertex[u] = true;
            if(dfs_low[v] > dfs_num[u]) printf(" Edge (%d, %d) is a bridge\n", u, v);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if(v != dfs_parent[u]) dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

int main() {
    dfs_num.assign(V, UNVISITED);
    dfs_parent.assign(V, 0);
    articulation_vertex.assign(V, 0);
    printf("Bridges:\n");
    for(int i = 0; i < V; ++i) if(dfs_num[i] == UNVISITED) {
        dfsRoot = i; rootChildren = 0;
        articulatioonPointAndBridge(i);
        articulation_vertex[dfsRoot] = rootChildren > 1;
    }
}