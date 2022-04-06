class Solution {
public:
    vector<string> findRepeatedDnaSequences(string str) {
        unordered_set<string> s;
        unordered_set<string> ans;
        const int n = str.length();
        auto start = str.begin();
        auto end = next(str.begin(), 10);
        for(int j = 10; j <= n; ++j) {
            auto [_, b] = s.emplace(start, end);
            if(!b) ans.emplace(start, end);
            start++, end++;
        }
        return vector<string>(ans.begin(), ans.end());
    }
};