#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define INF 2e9
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> AdjList;
AdjList graph;
vi dist;

void bellmanFord(int s) {
    dist[s] = 0;
    FOR(i,1,V-1) FOR(u,1,V) FOR(j,0,graph[u].size()-1) {
        auto [v, w] = graph[u][j];
        dist[v] = min(dist[v], dist[u]+w);
    }
    bool hasNegativeCycle = false;
    FOR(u,1,V) FOR(j,0,graph[u].size()-1) {
        auto [v, w] = graph[u][j];
        if(dist[v] > dist[u] + w) hasNegativeCycle = true;
    }
    if(hasNegativeCycle) cout << "HAS NEGATIVE CYCLE!!!!" << endl;
}

int main() {
    int V, E; cin >> V >> E;
    graph.resize(V+1);
    dist.assign(V+1, INF);
    FOR(i,1,E) {
        int u, v, w; cin >> u >> v >> w;
        graph[u].emplace_back({v, w});
        graph[v].emplace_back({u, w});
    }
    bellmanFord(1);
}