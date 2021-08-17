class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int ans{0};
        for(auto& word : words) {
            int i{0}, n = word.length(), j{-1}, ilen{1};
            for(; i < n; ++i) {
                if(i == n-1 || word[i] != word[i+1]) {
                    int j_start{j+1};
                    while(j+1 < s.length() && s[j+1] == word[i]) j++;
                    int jlen = j-j_start+1;
                    if(jlen == ilen) {}
                    else if(jlen < ilen) break;
                    else { // ilen < jlen
                        if(ilen == 0) break;
                        else if(jlen < 3) break;
                    }
                    ilen = 1;
                }
                else ilen++;
            }
            if(i == n && j == s.length()-1) ans++;
        }
        return ans;
    }
};