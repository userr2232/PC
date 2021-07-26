#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define UNVISITED -1
#define VISITED 1
#define INF 1e9
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> AdjList;
AdjList graph;
vi visited, min_dist;
int n, m;

void dfs(int s, int t) {
    visited[s] = VISITED;
    int& ans = min_dist[s];
    if(s == t) ans = 0;
    for(auto [v, w] : graph[s]) {
        if(visited[v] == UNVISITED) dfs(v, t);
        if(min_dist[v] != INF) ans = min(ans, min_dist[v] + w);
    }
}

int main() {
    int s, t;
    cin >> n >> m >> s >> t;
    int u, v, w;
    graph.resize(n+1);
    visited.assign(n+1, UNVISITED);
    min_dist.assign(n+1, INF);
    FOR(i,1,m) cin >> u >> v >> w, graph[u].push_back({v,w});
    dfs(s, t);
    if(min_dist[t] == INF) cout << "Unreachable";
    else cout << min_dist[s];
}