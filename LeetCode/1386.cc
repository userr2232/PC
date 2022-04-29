class Solution {
    int decide(bool two_five, bool four_seven, bool six_nine) {
        if(two_five || four_seven || six_nine) {
            if(two_five && six_nine) return 2;
            return 1;
        }
        return 0;
    }
    
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& seats) {
        auto cmp = [](const vector<int>& lhs, const vector<int>& rhs) {
            return lhs[0] < rhs[0] || lhs[0] == rhs[0] && lhs[1] < rhs[1];
        };
        sort(seats.begin(), seats.end(), cmp);
        seats.push_back({n+1, 1});
        int current_row = 0;
        int visited_rows = 0;
        int groups_in_visited_rows = 0;
        bool two_five{true}, four_seven{true}, six_nine{true};
        for(auto&& seat : seats) {
            int row = seat[0], col = seat[1];
            if(row != current_row) {
                if(current_row > 0) {
                    visited_rows++;
                    groups_in_visited_rows += decide(two_five, four_seven, six_nine);
                    two_five = true, four_seven = true, six_nine = true;
                }
                current_row = row;
            }
            if(col >= 2 && col <= 5) two_five = false;
            if(col >= 4 && col <= 7) four_seven = false;
            if(col >= 6 && col <= 9) six_nine = false;
        }
        return ((n-visited_rows) << 1) + groups_in_visited_rows;
    }
};