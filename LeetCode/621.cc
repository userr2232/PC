class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freqs(26, 0);
        for(auto task : tasks) {
            freqs[task - 'A']++;
        }
        sort(freqs.begin(), freqs.end());
        auto max_freq = freqs.back();
        freqs.pop_back();
        auto idle_time = (max_freq - 1) * n;
        while(!freqs.empty() && freqs.back()) {
            auto freq = freqs.back();
            freqs.pop_back();
            idle_time -= min(max_freq - 1, freq);
            if(idle_time <= 0) {
                idle_time = max(idle_time, 0);
                break;
            }
        }
        return tasks.size() + idle_time;
    }
};