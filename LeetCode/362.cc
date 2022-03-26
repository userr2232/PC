class HitCounter {
    deque<int> hits;
public:
    HitCounter() {
    }
    
    void hit(int timestamp) {
        hits.emplace_back(timestamp);
        auto it = lower_bound(hits.begin(), hits.end(), timestamp-300+1);
        hits.erase(hits.begin(), it);
    }
    
    int getHits(int timestamp) {
        auto it = lower_bound(hits.begin(), hits.end(), timestamp-300+1);
        int ans = distance(it, hits.end());
        hits.erase(hits.begin(), it);
        return ans;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */