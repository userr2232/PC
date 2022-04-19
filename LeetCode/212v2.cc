struct Trie{
    struct Node{
        vector<Node*> children = vector<Node*>(26, nullptr);
        bool is_leaf{false};
    };
    
    Node* root{nullptr};

    Trie(): root{new Node()} {
        
    }
    
    void add_word(const string& word) {
        Node* current{root};
        for(auto c : word) {
            if(auto& child = current->children[c-'a']; child != nullptr) 
                current = child;
            else current = child = new Node();
        }
        current->is_leaf = true;
    }
};

class Solution {    
    int m, n;
    Trie trie;
    vector<vector<bool>> visited;
    
    vector<string> search(const vector<vector<char>>& board) {
        vector<string> ans;
        for(int i = 0; i < m; ++i) for(int j = 0; j < n; ++j) {
            if(auto child = trie.root->children[board[i][j]-'a']; child != nullptr)
                dfs(child, board, ans, vector<char>(), i, j);
        }
        return ans;
    }
    
    bool valid(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    
    void dfs(Trie::Node* current, const vector<vector<char>>& board, vector<string>& ans, vector<char>&& str, int i = 0, int j = 0) {
        str.emplace_back(board[i][j]);
        visited[i][j] = true;
        if(current->is_leaf) ans.emplace_back(str.begin(), str.end()), current->is_leaf = false;
        for(int di = -1; di <= 1; ++di) for(int dj = -1; dj <= 1; ++dj) if(abs(di) != abs(dj)) {
            int new_i{i+di}, new_j{j+dj};
            if(!valid(new_i, new_j) || visited[new_i][new_j]) continue;
            if(auto child = current->children[board[new_i][new_j]-'a']; child != nullptr)
                dfs(child, board, ans, forward<vector<char>>(str), new_i, new_j);
        }
        visited[i][j] = false;
        str.pop_back();
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        visited.assign(m, vector<bool>(n, false));
        for(const auto& word : words)
            trie.add_word(word);
        return search(board);
    }
};