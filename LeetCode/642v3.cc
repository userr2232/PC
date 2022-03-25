class AutocompleteSystem {

    struct TrieNode {
        int count{0};
        unordered_map<char,TrieNode*> m;
    };
    
    struct cmp {
        bool operator()(const pair<string,int>& lhs, const pair<string,int>& rhs) {
            return (lhs.second < rhs.second) || (lhs.second == rhs.second && lhs.first > rhs.first);
        }
    };
    
    TrieNode* root{nullptr};
    vector<char> str;
    TrieNode* current{nullptr};
    priority_queue<pair<string,int>, vector<pair<string,int>>, cmp> pq;
    
    void add_sentence(const string& sentence, int num = 1) {
        return add_sentence(vector<char>(sentence.begin(), sentence.end()), num);
    }
    
    void add_sentence(const vector<char>& sentence, int num = 1) {
        if(root == nullptr) root = new TrieNode();
        TrieNode* current = root;
        const int n = sentence.size();
        for(int i = 0; i < n; ++i) {
            char c = sentence[i];
            if(auto it = current->m.find(c); it != current->m.end()) {
                current = it->second;
            }
            else { 
                current = current->m[c] = new TrieNode();
            }
        }
        current->count += num;
    }
    
    void dfs(TrieNode* current) {
        if(current == nullptr) return;
        if(current->count) {
            add_to_pq(current->count);
        }
        for(auto [c, node] : current->m) {
            str.emplace_back(c);
            dfs(node);
            str.pop_back();
        }
    }
    
    void add_to_pq(int count) {
        string s(str.begin(), str.end());
        pq.emplace(move(s), count);
    }
    
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        const int n = sentences.size();
        for(int i = 0; i < n; ++i) add_sentence(sentences[i], times[i]);
        current = root;
    }
    
    vector<string> input(char c) {
        vector<string> ans;
        if(c == '#') {
            add_sentence(str);
            str = {};
            current = root;
        }
        else {
            str.emplace_back(c);
            if(current == nullptr) 
                return ans;
            if(auto it = current->m.find(c); it != current->m.end()) {
                current = it->second;
                dfs(current);
            }
            else {
                current = nullptr;
            }
        }
        while(ans.size() < 3 && !pq.empty()) {
            ans.emplace_back(pq.top().first);
            pq.pop();
        }
        pq = {};
        return ans;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */