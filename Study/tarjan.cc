#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#define UNVISITED -1
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> AdjList;

int dfsNumberCounter, SCC;
vector<bool> visited;
stack<int> st;
vi dfs_num, dfs_low;
AdjList graph;

void tarjanSCC(int u) {
    dfs_num[u] = dfs_low[u] = ++dfsNumberCounter;
    visited[u] = true;
    st.emplace(u);
    FOR(j,0,graph[u].size()-1) {
        auto [v, _] = graph[u][j];
        if(dfs_num[v] == UNVISITED) tarjanSCC(v);
        if(visited[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if(dfs_low[u] == dfs_num[u]) {
        cout << "SCC: " << ++SCC << endl;
        while(true) {
            int v = st.top();
            st.pop();
            cout << v << " ";
            visited[v] = false;
            if(v == u) break;
        }
    }
}

int main() {
    int V, E; cin >> V >> E;
    visited.assign(V, false);
    dfs_num.assign(V, UNVISITED);
    dfs_low.assign(V, -1);
    graph.resize(V);
    FOR(i,1,E) {
        int u, v, w; cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }
    FOR(u,0,V-1) if(dfs_num[u] == UNVISITED) tarjanSCC(u);
}