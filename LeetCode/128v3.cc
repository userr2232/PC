class UnionFind {
private:
    unordered_map<int,int> p;
    unordered_map<int,int> rank;
    unordered_map<int,int> union_size;
public:
    UnionFind(vector<int> const& nums) {
        for(auto&& num : nums) 
            p[num] = num, rank[num] = 0, union_size[num] = 1;
        for(auto&& num : nums)
            unionSet(num, num-1), unionSet(num, num+1);
    }
    
    int findSet(int i) {
        return p[i] == i ? i : p[i] = findSet(p[i]);
    }
    
    void unionSet(int i, int j) {
        if(p.count(i) == 0 || p.count(j) == 0) return;
        int x{findSet(i)}, y{findSet(j)};
        if(x == y) return;
        if(rank[x] > rank[y]) p[y] = x, union_size[x] += union_size[y];
        else {
            p[x] = y;
            if(rank[x] == rank[y]) rank[y]++;
            union_size[y] += union_size[x];
        }
    }
    
    int size(int i) {
        return union_size[findSet(i)];
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        UnionFind uf(nums);
        int max_size{0};
        for(auto&& num : nums) max_size = max(max_size, uf.size(num));
        return max_size;
    }
};