class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for(string str : strs) {
            string hash = "";
            vector<int> counts(26, 0);
            for(char c : str) counts[c-'a']++;
            for(int i = 0; i < 26; ++i) hash += "#"+to_string(counts[i]);
            groups[hash].push_back(str);
        }
        vector<vector<string>> ans(groups.size());
        int i = -1;
        for(auto [_, v] : groups) {
            i++;
            for(auto str : v) ans[i].push_back(str);
        }
        return ans;
    }
};