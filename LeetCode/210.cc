#define UNEXPLORED -1
#define EXPLORED 1
#define VISITED 2

class Solution {
    typedef vector<vector<int>> AdjList;
    AdjList graph;
    vector<int> state;
    stack<int> st;
    bool cycle{false};
    
    void dfs(int u) {
        if(cycle) return;
        state[u] = EXPLORED;
        for(const auto& v : graph[u]) {
            if(state[v] == UNEXPLORED) dfs(v);
            else if(state[v] == EXPLORED) {
                cycle = true;
                return;
            }
        }
        state[u] = VISITED;
        st.emplace(u);
    }
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        state.assign(numCourses, UNEXPLORED);
        for(const auto& e : prerequisites) {
            int u{e[0]}, v{e[1]};
            graph[v].emplace_back(u);
        }
        for(int i = 0; i < numCourses; ++i) {
            if(!cycle && state[i] != VISITED) dfs(i);
        }
        if(cycle) return {};
        vector<int> ans;
        while(!st.empty()) {
            ans.emplace_back(st.top());
            st.pop();
        }
        return ans;
    }
};