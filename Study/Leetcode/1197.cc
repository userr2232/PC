class Solution {
public:
    int minKnightMoves(int x, int y) {
        if(x == 0 && y == 0) return 0;
        x = abs(x), y = abs(y);
        int dist{0};
        while(x > 4 || y > 4) {
            dist++;
            if(x >= y) {
                x -= 2;
                y -= y >= 1 ? 1 : -1;
            }
            else {
                y -= 2;
                x -= x >= 1 ? 1 : -1;
            }
        }
        set<pair<int,int>> visited;
        queue<pair<int,int>> q;
        q.push({0,0});
        visited.insert({0,0});
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto [cur_x, cur_y] = q.front();
                q.pop();
                for(int i = -2; i <= 2; ++i) for(int j = -2; j <= 2; ++j) if(j != 0 && i != 0 && abs(j) != abs(i)) {
                    if(visited.count({cur_x+i, cur_y+j}) == 0) {
                        if(cur_x+i == x && cur_y+j == y) return dist+1;
                        q.push({cur_x+i, cur_y+j});
                        visited.insert({cur_x+i, cur_y+j});
                    }
                }
            }
            dist++;
        }
        return 0;
    }
};