class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.length() > s.length()) return {};
        vector<int> counter(26, 0), local_counter(26, 0);
        for(auto c : p) counter[c-'a']++;
        int l = p.size();
        const int n = s.length();
        vector<int> ans;
        for(int i = 0; i < l; ++i) local_counter[s[i]-'a']++;
        if(counter == local_counter) ans.emplace_back(0);
        for(int i = 1; i <= n-l; ++i) {
            local_counter[s[i-1]-'a']--;
            local_counter[s[i+l-1]-'a']++;
            if(local_counter == counter) ans.emplace_back(i);
        }
        return ans;
    }
};