#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<pair<int,ii>> EdgeList;

EdgeList graph;

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
    bool isSameSet(int i, int j){
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j){
        int x{findSet(i)}, y{findSet(j)};
        if(rank[x] > rank[y]) p[y] = x;
        else {
            p[x] = y;
            if(rank[x] == rank[y]) rank[y]++;
        }
    }
};

int main() {
    int V, E, mst_cost{0};
    // initialize graph; V;
    E = graph.size();
    sort(graph.begin(), graph.end());
    UnionFind uf(V);
    FOR(i,0,E-1) {
        auto [w, nodes] = graph[i];
        auto [u, v] = nodes;
        if(!uf.isSameSet(u, v))
            mst_cost += w, uf.unionSet(u, v);
    }
    cout << mst_cost << "\n";
    return 0;
}