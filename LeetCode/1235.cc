class Solution {
public:
    int n;
    vector<int> memo;
    vector<pair<int,pair<int,int>>> v;
    vector<int> startTime;
    
    int dp(int id) {
        if(id == n) return 0;
        int& ans = memo[id];
        if(ans != -1) return ans;
        auto [start, e_p] = v[id];
        auto [end, profit] = e_p;
        int next_id = lower_bound(startTime.begin()+id+1, startTime.end(), end) - startTime.begin();
        return ans = max(profit+dp(next_id), dp(id+1));
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        v.resize(n);
        memo.assign(n, -1);
        for(int i = 0; i < n; ++i) v[i] = {startTime[i], {endTime[i], profit[i]}};
        sort(v.begin(), v.end());
        this->startTime = startTime;
        sort(this->startTime.begin(), this->startTime.end());
        return dp(0);
    }
};