class Solution {
    string simple_hash(const string& str) {
        vector<int> v(26, 0);
        for(auto c : str) {
            v[c-'a']++;
        }
        string ans;
        for(auto e : v) {
            ans += to_string(e) + "#";
        }
        return ans;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> m;
        for(auto& str : strs) {
            const auto& h = simple_hash(str);
            m[h].emplace_back(move(str));
        }
        vector<vector<string>> ans;
        int i{0};
        for(auto it = m.begin(); it != m.end(); ++it, ++i) {
            ans.emplace_back();
            for(auto& str : it->second) {
                ans[i].emplace_back(move(str));
            }
        }
        return ans;
    }
};