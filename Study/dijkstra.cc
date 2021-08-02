#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define INF 1e9
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> AdjList;
AdjList graph;
vi dist;

void dijkstra(int s) {
    dist[s] = 0;
    priority_queue<ii, vii, greater<ii>> pq; pq.push({0, s});
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(d > dist[u]) continue;
        FOR(j,0,graph[u].size()-1) {
            auto [v, w] = graph[u][j];
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int V, E; cin >> V >> E;
    graph.resize(V+1);
    FOR(i,1,E) {
        int u, v, w; cin >> u >> v >> w;
        graph[u].emplace_back({v, w});
        graph[v].emplace_back({u, w});
    }
    dist.assign(V+1, INF);
    dijkstra(1);
}