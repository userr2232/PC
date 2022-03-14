class TicTacToe {
    int winner, n;
    vector<int> vertical, horizontal;
    int d1, d2;
    
public:
    TicTacToe(int n): d1{0}, d2{0}, winner{0}, n{n} {
        vertical.assign(n, 0);
        horizontal.assign(n, 0);
    }
    
    int move(int row, int col, int player) {
        if(winner) return winner;
        if(player == 2) player = -1;
        horizontal[row] += player;
        vertical[col] += player;
        if(col == row) d1 += player;
        if(row + col == n-1) d2 += player;
        if(player == -1) player = 2;
        if(abs(horizontal[row]) == n) return winner = player;
        else if(abs(vertical[col]) == n) return winner = player;
        else if(abs(d1) == n) return winner = player;
        else if(abs(d2) == n) return winner = player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */