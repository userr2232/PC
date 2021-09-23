class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        const int N = stations.size();
        vector<long> dp(N+1, 0);
        dp[0] = startFuel;
        for(int i = 0; i < N; ++i) {
            // cout << "we are on station " << i << " at " << stations[i][0] << endl;
            for(int t = i; t >= 0; --t) if(dp[t] >= stations[i][0]) // we go in reverse to not consider the same station twice
                dp[t+1] = max(dp[t+1], dp[t]+stations[i][1]);//, cout << "furthest distance with " << t+1 << " stations: " << dp[t+1] << endl;
            // cout << endl;
        }
        // for(int i = 0; i <= N; ++i) cout << dp[i] << " ";
        for(int i = 0; i <= N; ++i) if(dp[i] >= target) return i;
        return -1;
    }
};
/*

TEST CASE:
1000
83
[[25,27],[36,187],[140,186],[378,6],[492,202],[517,89],[579,234],[673,86],[808,53],[954,49]]

t: i->0
CORRECT:
we are on station 0 at 25
furthest distance with 1 stations: 110

we are on station 1 at 36
furthest distance with 2 stations: 297
furthest distance with 1 stations: 270

we are on station 2 at 140
furthest distance with 3 stations: 483
furthest distance with 2 stations: 456

we are on station 3 at 378
furthest distance with 4 stations: 489
furthest distance with 3 stations: 483

we are on station 4 at 492

we are on station 5 at 517

we are on station 6 at 579

we are on station 7 at 673

we are on station 8 at 808

we are on station 9 at 954

83 270 456 483 489 0 0 0 0 0 0 


t:  0->i
INCORRECT:
we are on station 0 at 25
furthest distance with 1 stations: 110

we are on station 1 at 36
furthest distance with 1 stations: 270
furthest distance with 2 stations: 457

we are on station 2 at 140
furthest distance with 2 stations: 457
furthest distance with 3 stations: 643

we are on station 3 at 378
furthest distance with 3 stations: 643
furthest distance with 4 stations: 649

we are on station 4 at 492
furthest distance with 4 stations: 845
furthest distance with 5 stations: 1047

we are on station 5 at 517
furthest distance with 4 stations: 845
furthest distance with 5 stations: 1047
furthest distance with 6 stations: 1136

we are on station 6 at 579
furthest distance with 4 stations: 877
furthest distance with 5 stations: 1111
furthest distance with 6 stations: 1345
furthest distance with 7 stations: 1579

we are on station 7 at 673
furthest distance with 5 stations: 1111
furthest distance with 6 stations: 1345
furthest distance with 7 stations: 1579
furthest distance with 8 stations: 1665

we are on station 8 at 808
furthest distance with 5 stations: 1111
furthest distance with 6 stations: 1345
furthest distance with 7 stations: 1579
furthest distance with 8 stations: 1665
furthest distance with 9 stations: 1718

we are on station 9 at 954
furthest distance with 6 stations: 1345
furthest distance with 7 stations: 1579
furthest distance with 8 stations: 1665
furthest distance with 9 stations: 1718
furthest distance with 10 stations: 1767

83 270 457 643 877 1111 1345 1579 1665 1718 1767 
*/