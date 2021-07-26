#include <iostream>
#include <vector>
#define UNVISITED -1
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> AdjList;
AdjList graph;
vi color;
int n, m;
bool bipartite = true;

void dfs(int u, bool c) {
    color[u] = c;
    for(auto v : graph[u]) {
        if(color[v] == UNVISITED) dfs(v, 1-c);
        else if(color[u] == color[v]) { bipartite = false; return; }
    }
}

void print() {
    for(auto e: color) if(e == 1) cout << "1 "; else if(e == 0) cout << "2 ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    color.assign(n+1, UNVISITED);
    graph.resize(n+1);
    int a, b;
    FOR(i,1,m) cin >> a >> b, graph[a].push_back(b), graph[b].push_back(a);
    FOR(i,1,n) if(color[i] == UNVISITED) dfs(i, 0);
    if(bipartite) cout << "YES" << endl, print();
    else cout << "NO" << endl;
}