#include <iostream>
#include <vector>
#include <queue>
#define INF 2e9
using namespace std;

bool is_bipartite(int s = 0) {
    queue<int> q; q,push(s);
    vi color(V, INF); color[s] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int j = 0; j < AdjList[u].size(); ++j) {
            auto [v, _] = AdjList[u][j];
            if(color[v] == INF) color[v] = 1 - color[u], q.push(v);
            else if(color[v] == color[u]) return false;
        }
    }
    return true;
}