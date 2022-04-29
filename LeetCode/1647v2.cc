class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26, 0);
        for(auto c : s) v[c-'a']++;
        sort(v.begin(), v.end());
        int min_to_right = v[25]+1;
        int ans{0};
        for(int i = 25; i >= 0; --i) {
            if(v[i] > 0 && v[i] >= min_to_right) {
                ans += v[i] - max(0, min_to_right-1);
                v[i] = max(0, min_to_right-1);
            }
            min_to_right = v[i];
        }
        return ans;
    }
};