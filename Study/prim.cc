#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> AdjList;

void process(int u, priority_queue<ii,vii,greater<ii>>& pq, vector<bool>& taken, AdjList const& graph) {
    taken[u] = true;
    for(auto&& [v, w] : graph[u]) if(!taken[v])
        pq.emplace(w, v);
}

int main() {
    int V, E; cin >> V >> E;
    AdjList graph(V);
    vector<bool> taken(V, false);
    for(int i = 0; i < E; ++i) {
        int u, v, w; cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    priority_queue<ii,vii,greater<ii>> pq;
    process(0, pq, taken, graph);
    int mst_cost{0};
    while(!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();
        if(!taken[u]) mst_cost += w, process(u, pq, taken, graph);
    }
    return 0;
}