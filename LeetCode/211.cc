class WordDictionary {
    struct Node{
        vector<Node*> children = vector<Node*>(26, nullptr);
        bool is_leaf{false};
    };
    
    Node* root;
public:
    WordDictionary(): root{nullptr} {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* current{root};
        for(auto&& c : word) {
            if(auto child = current->children[c-'a']; child == nullptr)
                current = current->children[c-'a'] = new Node();
            else current = current->children[c-'a'];
        }
        current->is_leaf = true;
    }
    
    bool dfs(Node* current, int&& i, const string& word) {
        if(i == word.length()) {
            if(current->is_leaf) return true;
            return false;
        }
        char c = word[i];
        if(c == '.') {
            for(auto&& child : current->children)
                if(child != nullptr && dfs(child, forward<int>(i+1), word)) 
                    return true;
            return false;
        }
        else {
            if(auto child = current->children[c-'a']; child != nullptr)
                return dfs(child, forward<int>(i+1), word);
            return false;
        }
        return false;
    }
    
    bool search(string word) {
        Node* current{root};
        return dfs(current, 0, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */