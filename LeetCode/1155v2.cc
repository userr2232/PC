const int MOD = 1e9+7;
class Solution {
    void add(int& a, int b) {
        a += b;
        if(a > MOD) a -= MOD;
    }

public:
    int numRollsToTarget(int n, int k, int target) {
        vector<int> ways(target+1, 0);
        ways[0] = 1;
        for(int dice = 0; dice < n; ++dice) {
            vector<int> new_ways(target+1, 0);
            for(int i = 1; i <= target; ++i) 
                add(ways[i], ways[i-1]);
            for(int i = 1; i <= target; ++i) {
                new_ways[i] = ways[i-1] - (i-k-1 >= 0 ? ways[i-k-1] : 0);
                if(new_ways[i] < 0)
                    new_ways[i] += MOD;
            }
            ways = move(new_ways);
        }
        return ways[target];
    }
};