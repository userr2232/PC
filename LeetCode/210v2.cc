class Solution {
    typedef vector<vector<int>> AdjList;
    const int UNVISITED = -1;
    const int EXPLORED = 1;
    const int VISITED = 2;
    
    bool topo_sort(vector<int>& ans, AdjList const& graph, vector<int>& dfs_num, int u) {
        dfs_num[u] = EXPLORED;
        for(auto&& v : graph[u]) {
            if(dfs_num[v] == UNVISITED) {
                if(topo_sort(ans, graph, dfs_num, v)) return true;
            }
            else if(dfs_num[v] == EXPLORED) return true;
        }
        ans.emplace_back(u);
        dfs_num[u] = VISITED;
        return false;
    }
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        AdjList graph(numCourses);
        for(auto&& ab : prerequisites) {
            int a = ab[0], b = ab[1];
            graph[b].emplace_back(a);
        }
        vector<int> dfs_num(numCourses, UNVISITED);
        vector<int> ans;
        for(int u = 0; u < numCourses; ++u) if(dfs_num[u] == UNVISITED) {
            if(topo_sort(ans, graph, dfs_num, u)) return {};
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};