class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int i{0}, j{0};
        const int n = s2.length();
        vector<int> v1(26, 0), v2(26, 0);
        for(auto&& c : s1) v1[c-'a']++;
        for(; j < n; ++j) {
            v2[s2[j]-'a']++;
            while(v2[s2[j]-'a'] > v1[s2[j]-'a']) v2[s2[i++]-'a']--;
            while(j-i+1 > s1.length()) v2[s2[i++]-'a']--;
            if(j-i+1 == s1.length()) return true;
        }
        return false;
    }
};