const int INF = 1e9;
class Solution {
    int n, k;
    vector<vector<int>> memo;
    
    int dp(int i, int w, const vector<vector<int>>& flights, const vector<vector<int>>& days) {
        if(i == n || w == k) return 0;
        int& ans = memo[i][w];
        if(ans != -INF) return ans;
        for(int j = 0; j < n; ++j) if(flights[i][j])
            ans = max(ans, dp(j, w+1, flights, days)+days[j][w]);
        return ans;
    }
    
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        n = flights.size();
        k = days[0].size();
        memo.assign(n, vector<int>(k, -INF));
        for(int i = 0; i < n; ++i) flights[i][i] = 1;
        return dp(0, 0, flights, days);
    }
};