#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define INF 2e9
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> AdjList;

vi dist;
AdjList graph;

void bellmanFord(int s) {
    dist[s] = 0;
    FOR(i,1,V-1) FOR(u,0,V-1) FOR(j,0,graph[u].size()-1) {
        auto [v, w] = graph[u][j];
        dist[v] = min(dist[v], dist[u]+w);
    }
    bool hasNegativeWeightCycle{false};
    FOR(u,0,V-1) FOR(j,0,graph[u].size()-1) {
        auto [v, w] = graph[u][j];
        if(dist[v] < dist[u]+w) hasNegativeWeightCycle = true;
    }
    if(hasNegativeWeightCycle) cout << "HAS NEGATIVE WEIGHT CYCLE!!!!" << endl;
}

int main() {
    cin >> V >> E;
    dist.assign(V, INF);
    graph.resize(V);
    FOR(i,1,E) {
        int u, v, w; cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }
    bellmanFord(0);
}