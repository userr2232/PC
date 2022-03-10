class LRUCache {
    const int capacity;
    unordered_map<int, list<pair<int,int>>::iterator> lookup_table;
    list<pair<int,int>> cache;
    
public:
    LRUCache(int capacity): capacity{capacity} {
    }
    
    int get(list<pair<int,int>>::iterator it) {
        cache.splice(cache.end(), cache, it);
        return it->second;
    }
    
    int get(int key) {
        if(auto it = lookup_table.find(key); it != lookup_table.end())
            return get(it->second);
        return -1;
    }
    
    void put(int key, int value) {
        if(auto it = lookup_table.find(key); it != lookup_table.end()) {
            if(get(it->second) != value) 
                it->second->second = value;
        }
        else {
            if(cache.size() == capacity) {
                auto it = cache.begin();
                lookup_table.erase(it->first);
                cache.erase(it);
            }
            cache.emplace_back(key, value);
            auto last = --cache.end();
            lookup_table.emplace(key, last);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */