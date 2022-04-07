class UnionFind{
    vector<int> p, rank;
public:
    UnionFind(int n) {
        p.resize(n);
        rank.assign(n, 0);
        for(int i = 0; i < n; ++i) p[i] = i;
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
    
    int numComponents() {
        unordered_set<int> s;
        for(int i = 0; i < p.size(); ++i) s.emplace(findSet(i));
        return s.size();
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for(auto& edge : edges) {
            int u = edge[0], v = edge[1];
            uf.unionSet(u, v);
        }
        return uf.numComponents();
    }
};