class UnionFind{
    unordered_map<int,int> p, rank, size;
public:
    UnionFind(const vector<int>& A) {
        for(auto u : A) 
            p[u] = u, rank[u] = 0, size[u] = 1;
    }
    
    bool contains(int i) {
        return p.find(i) != p.end();
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
        if(rank[x] > rank[y]) p[y] = x, size[x] += size[y];
        else {
            p[x] = y, size[y] += size[x];
            if(rank[x] == rank[y]) rank[y]++;
        }
    }
    
    int maxSize() {
        int max_size{0};
        for(auto [_, sz] : size) max_size = max(max_size, sz);
        return max_size;
    }
    
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        UnionFind uf(nums);
        for(auto num : nums) {
            if(uf.contains(num-1) && !uf.isSameSet(num, num-1)) uf.unionSet(num, num-1);
            if(uf.contains(num+1) && !uf.isSameSet(num, num+1)) uf.unionSet(num, num+1);
        }
        return uf.maxSize();
    }
};