#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<pair<int,ii>> EdgeList;
const int N{101}, INF{(int)2e9};
int V, E, TC, invalid[N][N];
EdgeList graph, mst_edges;

class UnionFind {
private:
    vi p, rank;
public:
    UnionFind(int n) {
        p.assign(n,0);
        rank.assign(n,0);
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

int mst(bool b = false) {
    int mst_cost{0};
    UnionFind uf(V+1);
    FOR(i,0,E-1) {
        auto [w, nodes] = graph[i];
        auto [u, v] = nodes;
        if(invalid[u][v]) continue;
        if(!uf.isSameSet(u, v)) {
            if(b) mst_edges.push_back({w,{u,v}});
            mst_cost += w;
            uf.unionSet(u,v);
        }
    }
    auto r = uf.findSet(1);
    FOR(i,1,V) if(uf.findSet(i) != r) return INF;
    return mst_cost;
}

int second_mst() {
    int ans = INF;
    for(auto edge: mst_edges) {
        auto [_, nodes] = edge;
        auto [u, v] = nodes;
        invalid[u][v] = invalid[v][u] = 1;
        ans = min(ans, mst());
        invalid[u][v] = invalid[v][u] = 0;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    int a, b, c; 
    while(TC--) {
        cin >> V >> E;
        graph.clear();
        mst_edges.clear();
        FOR(i,1,E) {
            cin >> a >> b >> c;
            graph.push_back({c, {a,b}});
        }
        sort(graph.begin(), graph.end());
        cout << mst(true) << " " << second_mst() << endl;
    }
}