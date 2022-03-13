struct Node {
    bool leaf{false}, found{false};
    unordered_map<char,Node*> children;
};
class Solution {
    int m, n;
    Node* root{nullptr};
    vector<string> ans;
    vector<vector<bool>> visited;
    
    void build_trie(vector<string>& words) {
        if(root == nullptr) {
            root = new Node();
        }
        for(auto& word : words) {
            Node* current = root;
            for(auto c : word) {
                if(auto it = current->children.find(c); it != current->children.end()) 
                    current = it->second;
                else
                    current = current->children[c] = new Node();
            }
            current->leaf = true;
        }
    }
    
    bool valid(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, Node* current) {
        if(current == nullptr) return;
        for(int di = -1; di <= 1; ++di) for(int dj = -1; dj <= 1; ++dj) if(abs(di) != abs(dj)) {
            if(valid(i+di, j+dj)) {
                int i_new{i+di}, j_new{j+dj};
                char c = board[i_new][j_new];
                if(auto it = current->children.find(c); it != current->children.end()) {
                    if(!visited[i_new][j_new]) {
                        if(it->second->leaf) it->second->found = true;
                        visited[i_new][j_new] = true;
                        dfs(board, i_new, j_new, it->second);
                        visited[i_new][j_new] = false;
                    }
                }
            }
        }
    }
    
    void dfs(Node* current, string& s) {
        if(current == nullptr) return;
        if(current->found) ans.emplace_back(s);
        for(auto [c, child] : current->children) {
            s += c;
            dfs(child, s);
            s = s.substr(0, s.length()-1);
        }
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        build_trie(words);
        visited.assign(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i) for(int j = 0; j < n; ++j) {
            char c = board[i][j];
            if(auto it = root->children.find(c); it != root->children.end()) {
                if(it->second->leaf) it->second->found = true;
                visited[i][j] = true;
                dfs(board, i, j, it->second);
                visited[i][j] = false;
            }
        }
        string str;
        dfs(root, str);
        return ans;
    }
};