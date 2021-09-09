struct Trie{
    int times{0};
    string str{""};
    unordered_map<char,Trie*> children;
};

void insert(Trie*& root, const string& str, int times) {
    if(root == nullptr) root = new Trie();
    Trie* curr = root;
    for(char c : str) {
        if(curr->children.count(c) == 0) curr->children[c] = new Trie();
        curr = curr->children[c];
    }
    curr->times += times;
    curr->str = str;
}

class AutocompleteSystem {
    vector<string> results;
    string current_str;
    Trie *trie{nullptr}, *curr{nullptr};
    
    struct cmp{
        bool operator() (pair<int, string>& a, pair<int, string>& b){
            return a.first<b.first || a.first==b.first && a.second>b.second;
        }
    };
    
    priority_queue<pair<int, string>, vector<pair<int, string> >, cmp> pq;
    
    void dfs(Trie* root) {
        for(auto [c, curr] : root->children) {
            if(curr->times) pq.push({curr->times, curr->str});
            dfs(curr);
        }
    }
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        for(int i = 0; i < sentences.size(); ++i) insert(trie, sentences[i], times[i]);
        curr = trie;
    }
    
    vector<string> input(char c) {
        pq = {};
        if(c == '#') {
            insert(trie, current_str, 1);
            current_str = "";
            vector<string> ans = results;
            results = {};
            curr = trie;
            return ans;
        }
        current_str += c;
        if(curr == nullptr) return results = {};
        if(curr->children.count(c) == 0) {
            curr = nullptr;
            return results = {};
        }
        else {
            curr = curr->children[c];
        }
        if(curr->times) pq.push({curr->times, curr->str});
        dfs(curr);
        vector<string> ans;
        while(!pq.empty() && ans.size() < 3) {
            auto [times, str] = pq.top();
            pq.pop();
            ans.push_back(str);
        }
        return ans;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */