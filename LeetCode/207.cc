class Solution {
    const int UNVISITED = -1;
    const int EXPLORED = 1;
    const int VISITED = 2;
    bool has_cycle{false};
    vector<int> dfs_num;
    
    vector<vector<int>> graph;
    
    void dfs(int u) {
        dfs_num[u] = EXPLORED;
        for(auto v : graph[u]) {
            if(dfs_num[v] == EXPLORED) has_cycle = true;
            else if(dfs_num[v] == UNVISITED) dfs(v);
        }
        dfs_num[u] = VISITED;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        dfs_num.assign(numCourses, UNVISITED);
        graph.resize(numCourses);
        for(auto edge : prerequisites) {
            int u = edge[0], v = edge[1];
            graph[v].emplace_back(u);
        }
        for(int i = 0; i < numCourses; ++i) 
            if(dfs_num[i] == UNVISITED) dfs(i);
        return !has_cycle;
    }
};