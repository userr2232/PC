class LRUCache {
    int capacity;
    list<pair<int,int>> cache;
    unordered_map<int,list<pair<int,int>>::iterator> lookup_table;
public:
    LRUCache(int capacity): capacity{capacity} {
        
    }
    
    void update(list<pair<int,int>>::const_iterator it) {
        cache.splice(cache.end(), cache, it);
    }
    
    int get(int key) {
        if(auto it = lookup_table.find(key); it == lookup_table.end())
            return -1;
        else {
            int val = it->second->second;
            update(it->second);
            return val;
        }
    }
    
    void evict() {
        auto it = cache.begin();
        lookup_table.erase(it->first);
        cache.erase(it);
    }
    
    void put(int key, int value) {
        if(capacity > 0) {
            if(auto it = lookup_table.find(key); it == lookup_table.end()) {
                if(capacity == cache.size()) evict();
                lookup_table[key] = cache.emplace(cache.end(), key, value);
            }
            else {
                it->second->second = value;
                update(it->second);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */