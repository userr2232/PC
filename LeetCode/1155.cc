const int MOD = 1e9+7;
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<int> ways(target+1, 0);
        ways[0] = 1;
        for(int dice = 0; dice < n; ++dice) {
            vector<int> new_ways(target+1, 0);
            for(int face = 1; face <= k; ++face) for(int x = 0; x <= target; ++x) {
                    if(x+face <= target) {
                        int& tmp = new_ways[x+face];
                        tmp += ways[x];
                        if(tmp >= MOD)
                            tmp -= MOD;
                    }
                }
            ways = move(new_ways);
        }
        return ways[target];
    }
};