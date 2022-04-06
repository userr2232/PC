class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length() < s1.length()) return false;
        vector<int> v1(26, 0), v2(26, 0);
        for(auto c : s1) v1[c-'a']++;
        const int l = s1.length();
        for(int i = 0; i < l; ++i) {
            v2[s2[i]-'a']++;
        }
        if(v2 == v1) return true;
        for(int j = l; j < s2.length(); ++j) {
            v2[s2[j-l]-'a']--;
            v2[s2[j]-'a']++;
            if(v1 == v2) return true;
        }
        return false;
    }
};