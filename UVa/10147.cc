#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <complex>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<pair<double,ii>> EdgeList;
class UnionFind {
private: vi p, rank;
public:
    UnionFind(int n) {
        p.assign(n, 0);
        rank.assign(n, 0);
        FOR(i,0,n-1) p[i] = i;
    }
    int findSet(int i) {
        return p[i] == i ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
        int x{findSet(i)}, y{findSet(j)};
        if(rank[x] > rank[y]) p[y] = x;
        else {
            p[x] = y;
            if(rank[x] == rank[y]) rank[y]++;
        }
    }
};

void solve() {
    EdgeList graph;
    int N; cin >> N;
    int V = N;
    vector<complex<double>> vtxs(V);
    FOR(i,0,V-1) {
        double x, y;
        cin >> x >> y;
        vtxs[i] = complex<double>(x, y);
    }
    FOR(i,0,V-1) FOR(j,i+1,V-1) {
        auto d = norm(vtxs[i] - vtxs[j]);
        graph.push_back({d,{i,j}});
    }
    UnionFind uf(V);
    int M; cin >> M;
    while(M--) {
        int u, v;
        cin >> u >> v;
        uf.unionSet(u-1,v-1);
    }
    int E = graph.size();
    sort(graph.begin(), graph.end());
    vector<ii> ans;
    FOR(i,0,E-1) {
        auto w_nodes = graph[i];
        auto w = w_nodes.first;
        auto nodes = w_nodes.second;
        auto u = nodes.first;
        auto v = nodes.second;
        if(!uf.isSameSet(u, v)) ans.push_back({u+1,v+1}), uf.unionSet(u, v);
    }
    if(!ans.empty()) { for(auto [u, v] : ans) { cout << u << " " << v << "\n"; } }
    else { cout << "No new highways need\n"; }
}

int main() {
    int t; cin >> t;
    solve(); t--;
    while(t--) cout << "\n", solve();
    return 0;
}