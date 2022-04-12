class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> count_t, count_s;
        for(auto c : t) count_t[c]++;
        int i{0}, j{-1};
        for(auto [c, count] : count_t) {
            while(j+1 < s.length() && count_s[c] < count) count_s[s[++j]]++;
            if(count_s[c] < count) return "";
        }
        int ans = j-i+1, ans_i{i}, ans_j{j};
        while(j < s.length()) {
            while(count_t.count(s[i]) == 0 || count_s[s[i]] > count_t[s[i]]) count_s[s[i++]]--;
            if(ans > j-i+1) ans = j-i+1, ans_i = i, ans_j = j;
            if(++j < s.length()) count_s[s[j]]++;
        }
        return s.substr(ans_i, ans_j-ans_i+1);
    }
};