class Solution {
    int dfs(int u, const unordered_set<int>& vertices, unordered_set<int>& visited) {
        visited.emplace(u);
        int size{1};
        if(vertices.count(u-1) && !visited.count(u-1)) 
            size += dfs(u-1, vertices, visited);
        if(vertices.count(u+1) && !visited.count(u+1)) 
            size += dfs(u+1, vertices, visited);
        return size;
    }
    
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> vertices, visited;
        for(auto num : nums) vertices.emplace(num);
        int max_length{1};
        for(auto u : vertices) 
            if(!visited.count(u))
                max_length = max(max_length, dfs(u, vertices, visited));
        return max_length;
    }
};