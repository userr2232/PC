class Solution {
    struct State {
        int i{0}, j{0}, di{0}, dj{1};
    };
    
    struct StateHash {
        size_t operator()(State const& state) const {
            return hash<int>()(state.i) ^ hash<int>()(state.j) ^ hash<int>()(state.di) ^ hash<int>()(state.dj);
        }
    };
    
    struct StateEquals {
        bool operator()(State const& lhs, State const& rhs) const {
            return lhs.i == rhs.i && 
                    lhs.j == rhs.j && 
                    lhs.di == rhs.di && 
                    lhs.dj == rhs.dj;
        }
    };
    
    State next(State state) {
        state.i += state.di;
        state.j += state.dj;
        return state;
    }
    
    void turn(State& state) {
        swap(state.di, state.dj);
        state.dj = -state.dj;
    }
    
    bool valid(State const& state) {
        return state.i >= 0 && state.i < m && state.j >= 0 && state.j < n;
    }
    
    void dfs(State state, vector<vector<int>> const& room) {
        visited.emplace(state);
        cleaned.emplace(state.i, state.j);
        for(int i = 0; i < 4; ++i) {
            auto neighbor = next(state);
            if(!valid(neighbor) || room[neighbor.i][neighbor.j] == 1)
                turn(state);
            else {
                if(visited.count(neighbor) == 0) 
                    dfs(neighbor, room);
                return;
            }
        }
    }
    
    unordered_set<State,StateHash,StateEquals> visited;
    set<pair<int,int>> cleaned;
    int m, n;
    
public:
    int numberOfCleanRooms(vector<vector<int>>& room) {
        if(room.empty() || room[0].empty()) return 0;
        m = room.size(), n = room[0].size();
        dfs(State(), room);
        return cleaned.size();
    }
};