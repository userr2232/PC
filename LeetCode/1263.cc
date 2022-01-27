struct Coord{
    int i, j;
    Coord() = default;
    Coord(int i, int j): i{i}, j{j} {}
};

bool are_contiguous(const Coord& lhs, const Coord& rhs) {
    return abs(lhs.i - rhs.i)+abs(lhs.j - rhs.j) == 1;
}

enum Dir {left, right, up, down, end};

class Solution {
    int m, n;
    vector<vector<vector<bool>>> visited;
    vector<vector<bool>> valid;
    Coord t;
    
    bool is_valid(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n && valid[i][j];
    }
    
    void dfs(const Coord& b, const Coord& p, queue<pair<Coord,Coord>>& q, vector<bool>& reachable) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        stack<Coord> st;
        st.emplace(p);
        visited[p.i][p.j] = true;
        while(!st.empty()) {
            const auto person = st.top(); st.pop();
            if(are_contiguous(person, b)) {
                if(b.i - person.i != 0) {
                    if(person.i - b.i == -1) reachable[Dir::up] = true;
                    else reachable[Dir::down] = true;
                }
                else {
                    if(person.j - b.j == 1) reachable[Dir::right] = true;
                    else reachable[Dir::left] = true;
                }
                int s{0};
                for(const auto& b: reachable) s += b;
                if(s == 4) return;
            }
            for(int di = -1; di <= 1; ++di) for(int dj = -1; dj <= 1; ++dj) if(abs(di) != abs(dj)) {
                int new_i{person.i+di}, new_j{person.j+dj};
                if(!is_valid(new_i, new_j) || (new_i == b.i && new_j == b.j) || visited[new_i][new_j]) continue;
                visited[new_i][new_j] = true;
                st.emplace(new_i, new_j);
            }
        }
    }
    
public:
    int minPushBox(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        visited.assign(m, vector<vector<bool>>(n, vector<bool>(4, false)));
        valid.assign(m, vector<bool>(n, true));
        Coord p, b;
        for(int i = 0; i < m; ++i) for(int j = 0; j < n; ++j) {
            if(grid[i][j] == 'S') p.i = i, p.j = j;
            else if(grid[i][j] == 'B') b.i = i, b.j = j;
            else if(grid[i][j] == 'T') t.i = i, t.j = j;
            else if(grid[i][j] == '#') valid[i][j] = false;
            
        }
        queue<pair<Coord,Coord>> q;
        vector<bool> reachable(4);
        q.emplace(b, p);
        int dist{0};
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                const auto [box, person] = q.front(); q.pop();
                fill(reachable.begin(), reachable.end(), false);
                dfs(box, person, q, reachable);
                for(int dir = Dir::left; dir != Dir::end; ++dir) {
                    if(reachable[dir]) {
                        Dir d = static_cast<Dir>(dir);
                        int new_i{box.i}, new_j{box.j}, di{0}, dj{0};
                        switch (dir) {
                            case Dir::left:
                                dj = 1;
                                break;
                            case Dir::right:
                                dj = -1;
                                break;
                            case Dir::up:
                                di = 1;
                                break;
                            case Dir::down:
                                di = -1;
                                break;
                        }
                        new_i += di, new_j += dj;
                        if(is_valid(new_i, new_j) && !visited[new_i][new_j][dir]) {
                            visited[new_i][new_j][dir] = true;
                            Coord b{new_i, new_j}, p{box.i, box.j};
                            if(new_i == t.i && new_j == t.j) return dist+1;
                            q.emplace(b, p);
                        }
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};