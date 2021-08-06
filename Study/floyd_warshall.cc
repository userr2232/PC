#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> AdjMatrix;

AdjMatrix graph;

int main() {
    int V, E; cin >> V >> E;
    int u, v, w;
    graph.assign(V+1, vi(V+1, INF));
    FOR(i,1,E) cin >> u >> v >> w, graph[u][v] = w;
    FOR(k,1,V) FOR(i,1,V) FOR(j,1,V) graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}