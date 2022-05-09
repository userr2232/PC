class Solution {
    const int INF = 1e9;
    vector<vector<int>> memo;
    
    int dp(int mask, int currentTime, vector<int> const& tasks, int const& sessionTime) {
        if(mask == (1 << tasks.size())-1) return 1;
        int& ans = memo[mask][currentTime];
        if(ans != INF) return ans;
        for(int i = 0; i < tasks.size(); ++i) {
            if((mask & (1 << i)) == 0) {
                auto new_mask = mask ^ (1 << i);
                if(currentTime + tasks[i] <= sessionTime)
                    ans = min(ans, dp(new_mask, currentTime + tasks[i], tasks, sessionTime));
                ans = min(ans, 1 + dp(new_mask, tasks[i], tasks, sessionTime));
            }
        }
        return ans;
    }
    
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        memo.assign(1 << tasks.size(), vector<int>(sessionTime+1, INF));
        return dp(0, 0, tasks, sessionTime);
    }
};