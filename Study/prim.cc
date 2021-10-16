#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>
#include <queue>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> AdjList;

AdjList graph;
vector<bool> taken;
priority_queue<ii,vii,greater<ii>> pq;

void process(int u) {
    taken[u] = true;
    FOR(j,0,graph[u].size()-1) {
        auto [v, w] = graph[u][j];
        if(!taken[v]) pq.emplace(w, v);
    }
}

int main() {
    int V, E; cin >> V >> E;
    graph.resize(V);
    taken.assign(V, false);
    FOR(i,1,E) {
        int u, v, w; cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    process(0);
    int mst_cost{0};
    while(!pq.empty()) {
        auto [w, v] = pq.top(); pq.pop();
        if(!taken[v]) mst_cost += w, process(v);
    }
    cout << "mst cost: " << mst_cost << endl;
    return 0;
}