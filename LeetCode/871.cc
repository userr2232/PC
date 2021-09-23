class Solution {
public:
    int minRefuelStops(int target, int tank, vector<vector<int>>& stations) {
        priority_queue<long> pq;
        int ans{0}, prev{0};
        for(const auto& station : stations) {
            int location = station[0];
            int capacity = station[1];
            tank -= location - prev;
            while(!pq.empty() && tank < 0) tank += pq.top(), pq.pop(), ans++;
            if(tank < 0) return -1;
            pq.push(capacity);
            prev = location;
        }
        {
            tank -= target - prev;
            while(!pq.empty() && tank < 0) tank += pq.top(), pq.pop(), ans++;
            if(tank < 0) return -1;
        }
        return ans;
    }
};

