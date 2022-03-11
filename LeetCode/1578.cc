class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int group_size{0}, group_time{0}, group_max_time{0}, total_time{0};
        for(int i = 0; i < colors.length(); ++i) {
            if(i == 0 || colors[i] != colors[i-1]) {
                if(group_size > 1) total_time += group_time - group_max_time;
                group_size = 1;
                group_time = neededTime[i];
                group_max_time = neededTime[i];
            }
            else {
                group_size++;
                group_time += neededTime[i];
                group_max_time = max(group_max_time, neededTime[i]);
            }
        }
        if(group_size > 1) total_time += group_time - group_max_time;
        return total_time;
    }
};