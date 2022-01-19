class UnionFind {
    vector<int> p, rank;
public:
    UnionFind(size_t n): p(n), rank(n, 0) {
        for(int i = 0; i < p.size(); ++i) p[i] = i;
    }
    
    int findSet(int i) {
        return p[i] = (p[i] == i ? i : findSet(p[i]));
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

class Solution {
    typedef vector<vector<int>> AdjList;
    AdjList graph;
    map<string, unordered_set<int>> email_row;
    vector<bool> visited;
    vector<pair<int,set<string>>> ans;
    
    void dfs(int u, int root, vector<vector<string>>& accounts) {
        visited[u] = true;
        for(int j = 1; j < accounts[u].size(); ++j) {
            ans[root].second.emplace(accounts[u][j]);
        }
        for(auto& v : graph[u]) {
            if(!visited[v]) dfs(v, root, accounts);
        }
    }
    
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for(int i = 0; i < accounts.size(); ++i) {
            vector<string>& account = accounts[i];
            auto& name = account[0];
            for(int j = 1; j < account.size(); ++j) {
                auto& email = account[j];
                email_row[email].emplace(i);
            }
        }
        UnionFind uf(accounts.size());
        for(const auto& [email, positions] : email_row) {
            int prev{-1};
            for(const auto& row : positions) {
                if(prev != -1) uf.unionSet(row, prev);
                prev = row;
            }
        }
        graph.resize(accounts.size());
        visited.assign(accounts.size(), false);
        for(int i = 0; i < accounts.size(); ++i) {
            int u{i}, v{uf.findSet(i)};
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        int c{0};
        for(int u = 0; u < graph.size(); ++u)
            if(!visited[u])
                ans.emplace_back(u, set<string>()), dfs(u, c++, accounts);
        vector<vector<string>> f;
        int i{0};
        for(const auto& [row, emails] : ans) {
            f.emplace_back();
            f[i].emplace_back(accounts[row][0]);
            for(const auto& email : emails) {
                f[i].emplace_back(email);
            }
            i++;
        }
        return f;
    }
};