/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        map<int,int> m;
        
        for(const auto& intervals : schedule) for(const auto& interval : intervals)
            m[interval.start]++, m[interval.end]--;
        
        int start{-1}, score{0};
        vector<Interval> ans;
        
        for(const auto& [k, v] : m) {
            score += v;
            if(start == -1 && score == 0) start = k;
            if(start != -1 && score != 0) ans.emplace_back(Interval(start,k)), start = -1;
        }
        return ans;
    }
};