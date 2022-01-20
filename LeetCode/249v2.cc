class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        map<string, vector<int>> m;
        int i{0};
        for(const auto& s : strings) {
            string str;
            char initial = s[0];
            for(const auto& c : s) str += (c-initial+26)%26;
            m[str].emplace_back(i);
            i++;
        }
        vector<vector<string>> ans(m.size());
        i = 0;
        for(const auto& [_, positions] : m) {
            for(const auto& pos : positions)
                ans[i].emplace_back(move(strings[pos]));
            i++;
        }
        return ans;
    }
};