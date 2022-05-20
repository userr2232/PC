class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto&& stone : stones) pq.emplace(stone);
        while(pq.size() > 1) {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            y -= x;
            if(y > 0) pq.emplace(y);
        }
        if(pq.empty()) return 0;
        return pq.top();
    }
};