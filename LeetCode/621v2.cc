class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> task_counter;
        for(auto&& task : tasks) task_counter[task]++;
        priority_queue<int> max_heap;
        for(auto&& [_, count] : task_counter)
            max_heap.emplace(count);
        int t{0};
        queue<pair<int,int>> q;
        while(!max_heap.empty() || !q.empty()) {
            if(!q.empty() && q.front().second == t) {
                max_heap.emplace(q.front().first);
                q.pop();
            }
            if(max_heap.empty()) {
                auto [count, next_t] = q.front();
                q.pop();
                t += next_t-t;
                max_heap.emplace(count);
            }
            auto count = max_heap.top();
            t++;
            max_heap.pop();
            if(--count > 0)
                q.emplace(count, t+n);
        }
        return t;
    }
};