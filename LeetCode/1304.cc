class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n % 2) ans.emplace_back(0), n--;
        while(n) 
            ans.emplace_back(n), ans.emplace_back(-n), n -= 2;
        return ans;
    }
};