#define INF 2e9
class Solution {
    vector<vector<bool>> adjMatrix;
    vector<int> rank;
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        adjMatrix.assign(n, vector<bool>(n, false));
        rank.assign(n, 0);
        int max_rank = -INF, second_max_rank = -INF;
        for(auto& road : roads) {
            int a{road[0]}, b{road[1]};
            rank[a]++, rank[b]++;
            adjMatrix[a][b] = adjMatrix[b][a] = true;
        }
        int max_net_rank{0};
        for(int i = 0; i < n; ++i) for(int j = i+1; j < n; ++j) {
            max_net_rank = max(max_net_rank, rank[i]+rank[j]-(adjMatrix[i][j]));
        }
        return max_net_rank;
    }
};