#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> AdjList;
typedef long long ll;
AdjList graph;
vector<bool> taken;
set<int> not_taken;
ll cc_id = 0, ccvs;
set<pair<int,int>> edges;

void dfs(int v) {
    taken[v] = true;
    not_taken.erase(v);
    ccvs++;
    for(auto nb : graph[v]) {
        edges.insert({min(v,nb), max(v,nb)});
        if(taken[nb]) continue;
        dfs(nb);
    }
}

int main() {
    int V, E, u, v; cin >> V >> E;
    graph.resize(V+1);
    taken.assign(V+1, false);
    for(int i = 1; i <= V; ++i) not_taken.insert(i);
    for(int i = 1; i <= E; ++i) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    while(!not_taken.empty()) {
        cc_id++;
        ccvs = 0;
        edges.clear();
        auto v = *(not_taken.begin());
        not_taken.erase(v);
        dfs(v);
        if(edges.size() != ccvs*(ccvs-1)/2) { cout << "NO\n"; return 0; }
    }
    cout << "YES\n";
    return 0;
}