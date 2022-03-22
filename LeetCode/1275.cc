class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int winner{0};
        vector<int> horizontal(3, 0), vertical(3, 0);
        int d1{0}, d2{0};
        int player = 1;
        int j{0};
        for(auto move : moves) {
            ++j;
            int i{move[0]}, j{move[1]};
            horizontal[i] += player;
            vertical[j] += player;
            if(i == j) d1 += player;
            if(i+j == 2) d2 += player;
            if(auto val1 = max({horizontal[i], vertical[j], d1, d2}); val1 == 3)
                winner = 1;
            else if(auto val2 = min({horizontal[i], vertical[j], d1, d2}); val2 == -3)
                winner = -1;
            player *= -1;
            if(winner) break;
        }
        if(winner == 0 && j < 9) return "Pending";
        else if(winner == 0) return "Draw";
        else if(winner == 1) return "A";
        else return "B";
    }
};