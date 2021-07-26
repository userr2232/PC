#include <iostream>
#include <vector>
#define UNVISITED 0
#define VISITED 2
#define EXPLORED 1
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> AdjList;

AdjList graph;
vi visited, tsort;
int n, m; 
bool acyclic = true;

void dfs(int u) {
    visited[u] = EXPLORED;
    for(auto v : graph[u]) {
        if(visited[v] == UNVISITED) dfs(v);
        if(visited[v] == EXPLORED) acyclic = false;
    }
    visited[u] = VISITED;
    tsort.push_back(u);
}

void print() {
    for(int i = tsort.size()-1; i >= 0; --i) cout << tsort[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    graph.resize(n+1);
    visited.assign(n+1,UNVISITED);
    int a, b;
    FOR(i,1,m) cin >> a >> b, graph[a].push_back(b);
    FOR(i,1,n) if(visited[i] == UNVISITED) dfs(i);
    if(acyclic) print();
    else cout << -1 << endl;
}