class LFUCache {
    unordered_map<int,list<pair<int,pair<int,int>>>> multilevel_cache;
    unordered_map<int,list<pair<int,pair<int,int>>>::iterator> lookup_table;
    int capacity, min_freq, size;
public:
    LFUCache(int capacity): capacity{capacity}, min_freq{0}, size{0} {
    }
    
    void move_up(list<pair<int,pair<int,int>>>::iterator it) {
        auto&& [freq, k_v] = *it;
        multilevel_cache[freq+1].splice(multilevel_cache[freq+1].end(), multilevel_cache[freq], it);
        if(multilevel_cache[freq].empty()) {
            multilevel_cache.erase(freq);
            if(freq == min_freq) min_freq++;
        }
        freq++;
    }
    
    int get(int key) {
        auto it = lookup_table.find(key);
        if(it == lookup_table.end()) return -1;
        auto list_it = it->second;
        int value = list_it->second.second;
        move_up(list_it);
        return value;
    }
    
    void evict() {
        lookup_table.erase(multilevel_cache[min_freq].front().second.first);
        multilevel_cache[min_freq].pop_front();
        if(multilevel_cache[min_freq].empty())
            multilevel_cache.erase(min_freq);
        size--;
    }
    
    void emplace(int key, int value) {
        min_freq = 1;
        auto&& cache_level = multilevel_cache[min_freq];
        lookup_table[key] = cache_level.emplace(cache_level.end(), make_pair(min_freq, make_pair(key, value)));
        size++;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;
        auto it = lookup_table.find(key);
        if(it == lookup_table.end()) {
            if(size == capacity) evict();
            emplace(key, value);
        }
        else {
            auto list_it = it->second;
            list_it->second.second = value;
            move_up(list_it);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */