#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#define UNVISITED 0
#define VISITED 1
#define EXPLORED 2
using namespace std;

void graphCheck(int u) {
    dfs_num[u] = EXPLORED;
    for(int j = 0; j < AdjList[u].size(); ++j) {
        auto [v, _] ] AdjList[u][j];
        if(dfs_num[v] == UNVISITED) { // EXPLORED->UNVISITED
            dfs_parent[v] = u;
            graphCheck(v);
        }
        else if(dfs_num[v] == EXPLORED) { // EXPLORED->EXPLORED
            if(v == dfs_parent[u]) printf(" Two ways (%d, %d)-(%d, %d)\n", u, v, v, u);
            else printf(" Back Edge (%d, %d) (Cycle)\n", u, v);
        }
        else if(dfs_num[v] == VISITED) // EXPLORED->VISITED
            printf(" Forward/Cross Edge (%d, %d)\n", u, v);
    }
    dfs_num[u] = VISITED;
}