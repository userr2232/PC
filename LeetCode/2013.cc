class DetectSquares {
    unordered_map<int,unordered_map<int,int>> rows;
    unordered_map<int,unordered_map<int,int>> cols;
    map<pair<int,int>,int> counter;
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        int row = point[0], col = point[1];
        rows[row][col]++;
        cols[col][row]++;
        counter[make_pair(row, col)]++;
    }
    
    int count(vector<int> point) {
        int row1 = point[0], col1 = point[1];
        int ans{0};
        for(auto&& [col2, count2] : rows[row1]) if(col2 != col1) {
            int length = abs(col1-col2);
            for(int i = 0; i < 2; ++i) {
                int row3 = row1 + length * (i & 1 ? 1 : -1), col3 = col2;
                int count3 = counter[make_pair(row3,col3)];
                int row4 = row3, col4 = col1;
                int count4 = counter[make_pair(row4,col4)];
                ans += count2 * count3 * count4;
            }
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */