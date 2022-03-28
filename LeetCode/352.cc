class SummaryRanges {
    set<int> starts, ends;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        if(starts.empty()) {
            starts.emplace(val);
            ends.emplace(val);
            return;
        }
        if(*starts.begin() >= val) {
            auto it = starts.begin();
            if(*it > val + 1) {
                starts.emplace(val);
                ends.emplace(val);
                return;
            }
            if(*it == val+1) {
                starts.erase(it);
                starts.emplace(val);
                return;
            }
            return;
        }
        if(*prev(ends.end()) <= val) {
            auto it = prev(ends.end());
            if(*it < val - 1) {
                starts.emplace(val);
                ends.emplace(val);
                return;
            }
            if(*it == val-1) {
                ends.erase(it);
                ends.emplace(val);
                return;
            }
            return;
        }
        auto next_start = starts.lower_bound(val);
        auto next_end = ends.lower_bound(val);
        if(next_start == starts.end() && next_end != ends.end()) return;
        if(*next_start == val) return;
        if(*next_start >= val+1) {
            if(*next_start > val+1) {
                if(*next_end < *next_start) return;
                auto prev_end = prev(next_end);
                if(*prev_end == val-1) {
                    ends.erase(prev_end);
                    ends.emplace(val);
                    return;
                }
                if(*prev_end < val-1) {
                    starts.emplace(val);
                    ends.emplace(val);
                    return;
                }
                return;
            }
            else if(*next_start == val+1) {
                auto prev_end = prev(next_end);
                if(*prev_end == val-1) {
                    ends.erase(prev_end);
                    starts.erase(next_start);
                    return;
                }
                if(*prev_end < val-1)  {
                    starts.erase(next_start);
                    starts.emplace(val);
                    return;
                }
                return;
            }
        }
    }
    
    vector<vector<int>> getIntervals() {
        int sz = starts.size();
        auto start_it = starts.begin();
        auto end_it = ends.begin();
        vector<vector<int>> ans;
        while(start_it != starts.end()) {
            ans.push_back({*start_it, *end_it});
            start_it++, end_it++;
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */