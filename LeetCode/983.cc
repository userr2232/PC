const int INF = 1e9;
class Solution {
    vector<int> memo;
    
    int dp(int i, const vector<int>& days, const vector<int>& costs) {
        if(i == days.size()) return 0;
        if(int& ans = memo[i]; ans != INF) return ans;
        else {
            int next_7 = i+1;
            for(; next_7 < days.size(); ++next_7) if(days[next_7] >= days[i]+7) break;
            int next_30 = i+1;
            for(; next_30 < days.size(); ++next_30) if(days[next_30] >= days[i]+30) break;
            return ans = min({costs[0] + dp(i+1, days, costs), 
                              costs[1] + dp(next_7, days, costs),
                              costs[2] + dp(next_30, days, costs)});
        }
    }
    
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memo.assign(366, INF);
        return dp(0, days, costs);
    }
};