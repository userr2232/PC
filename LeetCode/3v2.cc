class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> counter(256, 0);
        int i{0}, longest{0};
        for(int j = 0; j < s.length(); ++j) {
            if(++counter[s[j]] > 1) {
                while(counter[s[j]] > 1) 
                    counter[s[i++]]--;
            }
            longest = max(longest, j-i+1);
        }
        return longest;
    }
};