class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> s_counter(128, 0), t_counter(128, 0);
        int ans{0};
        for(auto&& c : t) t_counter[c]++;
        int i{0}, j{-1};
        for(auto&& c : t) {
            while(j+1 < s.length() && s_counter[c] < t_counter[c]) s_counter[s[++j]]++;
            if(s_counter[c] < t_counter[c]) return "";
        }
        int start{i}, min_length{j-i+1};
        while(j < s.length()) {
            while(s_counter[s[i]] > t_counter[s[i]]) s_counter[s[i++]]--;
            if(j-i+1 < min_length) min_length = j-i+1, start = i;
            if(++j < s.length()) s_counter[s[j]]++;
        }
        return s.substr(start, min_length);
    }
};