struct TrieNode{
    unordered_map<char,TrieNode*> children;
    bool is_leaf{false};
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* current{root};
        for(auto&& c : word) {
            if(auto it = current->children.find(c); it == current->children.end())
                current = current->children[c] = new TrieNode();
            else current = current->children[c];
        }
        current->is_leaf = true;
    }
    
    bool search(string word) {
        TrieNode* current{root};
        for(auto&& c : word) {
            if(auto it = current->children.find(c); it == current->children.end())
                return false;
            else current = current->children[c];
        }
        return current->is_leaf;
    }
    
    bool startsWith(string prefix) {
        TrieNode* current{root};
        for(auto&& c : prefix) {
            if(auto it = current->children.find(c); it == current->children.end())
                return false;
            else current = current->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */