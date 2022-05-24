class Solution {
    typedef vector<vector<int>> AdjList;
    AdjList graph;
    const int UNVISITED = -1;
    const int EXPLORED = 1;
    const int VISITED = 2;
    
    bool checkCycles(AdjList const& graph, vector<int>& dfs_num, int u = 0) {
        dfs_num[u] = EXPLORED;
        for(auto&& v : graph[u]) {
            if(dfs_num[v] == UNVISITED) {
                if(checkCycles(graph, dfs_num, v)) return true;
            }
            else if(dfs_num[v] == EXPLORED) return true;
        }
        dfs_num[u] = VISITED;
        return false;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        for(auto&& ab : prerequisites) {
            int a = ab[0], b = ab[1];
            graph[b].emplace_back(a);
        }
        vector<int> dfs_num(numCourses, UNVISITED);
        for(int u = 0; u < numCourses; ++u)
            if(dfs_num[u] == UNVISITED && checkCycles(graph, dfs_num, u)) return false;
        return true;
    }
};