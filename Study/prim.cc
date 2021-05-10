#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vii> AdjList;

AdjList graph;
vector<bool> taken;
priority_queue<ii> pq;

void process(int vtx) {
    taken[vtx] = true;
    FOR(i,0,graph[vtx].size()-1) {
        auto [u, w] = graph[vtx][i];
        if(!taken[u]) pq.push({-w,-u});
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // initialize graph
    int V = graph.size(), mst_cost{0};
    taken.assign(V, false);
    process(0);
    while(!pq.empty()) {
        auto [w, u] = pq.top();
        w *= -1, u *= -1;
        pq.pop();
        if(!taken[u]) mst_cost += w, process(u);
    }
    cout << mst_cost << "\n";
    return 0;
}