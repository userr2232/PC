class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int max_length{0}, max_freq{0};
        const int n = s.length();
        int i{0}, j{0};
        while(j < n) {
            max_freq = max(max_freq, ++count[s[j]-'A']);
            while(j-i+1-max_freq > k) count[s[i++]-'A']--;
            max_length = max(max_length, j-i+1);
            ++j;
        }
        return max_length;
    }
};