#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> AdjList;
AdjList graph;
vi comp;

void dfs(int u, int k) {
    comp[u] = k;
    for(auto v : graph[u]) if(!comp[v]) dfs(v, k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    comp.assign(n+1,0);
    graph = AdjList(n+1);
    int a, b;
    FOR(i,1,m) cin >> a >> b, graph[a].push_back(b), graph[b].push_back(a);
    int k = 0;
    FOR(i,1,n) if(!comp[i]) dfs(i, ++k);
    cout << k << "\n";
    FOR(i,1,n) cout << comp[i] << " ";
}