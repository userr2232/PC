struct Node {
    int count{0};
    bool leaf{false};
    unordered_map<char, Node*> children;
};

struct cmp {
    bool operator()(pair<int,string>& lhs, pair<int,string>& rhs) {
        return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second > rhs.second);
    }
};

class AutocompleteSystem {    
    Node* root{nullptr};
    Node* current;
    string current_str;
    priority_queue<pair<int,string>, vector<pair<int,string>>, cmp> pq;
    
    void store_sentence(const string& sentence, const int number = 1) {
        Node* current = root;
        for(char c : sentence) {
            if(auto it = current->children.find(c); it == current->children.end()) {
                current = current->children[c] = new Node();
            }
            else {
                current = it->second;
            }
        }
        current->leaf = true;
        current->count += number;
    }
    
    void build_trie(const vector<string>& sentences, const vector<int>& times) {
        root = new Node();
        int n = sentences.size();
        for(int i = 0; i < n; ++i)
            store_sentence(sentences[i], times[i]);
    }
    
    void dfs(Node* current, string& str) {
        if(current->leaf && current->count > 0) pq.emplace(current->count, str);
        for(const auto& [c, child] : current->children) {
            str += c;
            dfs(child, str);
            str = str.substr(0, str.size()-1);
        }
    }
    
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        build_trie(sentences, times);
        current = root;
    }
    
    vector<string> input(char c) {
        if(c == '#') {
            store_sentence(current_str);
            current_str = "";
            current = root;
            return {};
        }
        current_str += c;
        if(current == nullptr) return {};
        pq = {};
        if(auto it = current->children.find(c); it != current->children.end()) {
            current = it->second;
            dfs(current, current_str);
        }
        else {
            current = nullptr;
            return {};
        }
        vector<string> ans;
        while(!pq.empty() && ans.size() < 3) {
            auto [_, str] = pq.top();
            pq.pop();
            ans.emplace_back(str);
        }
        return ans;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */