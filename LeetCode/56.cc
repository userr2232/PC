class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // preprocess all intervals
        set<pair<int,int>> preprocessed_intervals;
        for(auto interval : intervals)
            preprocessed_intervals.insert({interval[0], interval[1]});
        // find connected components
        vector<vector<int>> contigs;
        pair<int,int> current_contig{-1, -1}, zero{-1, -1};
        for(auto interval : preprocessed_intervals) {
            if(current_contig == zero) {
                current_contig = interval;
            }
            else {
                if(current_contig.second >= interval.first) {
                    current_contig.second = max(current_contig.second, interval.second);
                }
                else {
                    contigs.push_back({current_contig.first, current_contig.second});
                    current_contig = interval;
                }
            }
        }
        contigs.push_back({current_contig.first, current_contig.second});
        return contigs;
    }
};