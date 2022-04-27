class Solution {
    vector<string> parse(string const& path) {
        const int n = path.length();
        string current;
        vector<string> tokens;
        for(int i = 0; i < n; ++i) {
            char c = path[i];
            if(c == '/') {
                if(current != "")
                    tokens.emplace_back(move(current));
            }
            else current += c;
        }
        if(current != "") tokens.emplace_back(move(current));
        return tokens;
    }
    
public:
    string simplifyPath(string path) {
        auto tokens = parse(path);
        vector<string> v;
        for(auto&& token : tokens) {
            if(token == ".") continue;
            else if(token == "..") {
                if(!v.empty())
                    v.pop_back();
            }
            else v.emplace_back(move(token));
        }
        string ans;
        for(auto&& name : v) ans += "/" + name;
        return ans.empty() ? "/" : ans;
    }
};