class Solution {
public:
    int minDeletions(string s) {
        vector<int> frequencies(26, 0);
        for(auto c : s) frequencies[c-'a']++;
        sort(frequencies.begin(), frequencies.end());
        int to_delete{0};
        int n = frequencies.size();
        for(int i = n-1; i > 0; --i) if(auto frequency = frequencies[i]; frequency) {
            for(int j = i-1; j >= 0; --j) {
                if(frequency == frequencies[j]) 
                    to_delete++, frequencies[j]--;
                else break;
            }
        }
        return to_delete;
    }
};