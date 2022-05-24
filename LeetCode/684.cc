class Solution {
    class UnionFind{
        vector<int> p, rank;
    public:
        UnionFind(int n) {
            p.resize(n);
            for(int i = 0; i < n; ++i) p[i] = i;
            rank.assign(n, 0);
        }
        
        int findSet(int i) {
            return p[i] == i ? i : (p[i] = findSet(p[i]));
        }
        
        bool isSameSet(int i, int j) {
            return findSet(i) == findSet(j);
        }
        
        void unionSet(int i, int j) {
            int x{findSet(i)}, y{findSet(j)};
            if(x == y) return;
            if(rank[x] > rank[y]) p[y] = x;
            else {
                p[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    };
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int n = edges.size();
        UnionFind uf(n+1);
        pair<int,int> cycle_edge;
        for(auto&& edge : edges) {
            int u = edge[0], v = edge[1];
            if(uf.isSameSet(u, v)) cycle_edge = {u, v};
            else uf.unionSet(u, v);
        }
        return {cycle_edge.first, cycle_edge.second};
    }
};