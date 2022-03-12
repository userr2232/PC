struct custom_hash {
    static const int m = 1e4;
    size_t operator()(uint64_t k) const {
        static const uint64_t p = 1e9+7;
        static uint64_t a = chrono::steady_clock::now().time_since_epoch().count() % p;
        while(a == 0) a = chrono::steady_clock::now().time_since_epoch().count() % p;
        static const uint64_t b = chrono::steady_clock::now().time_since_epoch().count() % p;
        return ((a * k + b )% p) % m;
    }
};

class MyHashMap {
    custom_hash hash;
    vector<list<pair<int,int>>> hash_table;
    
public:
    MyHashMap() {
        hash_table.resize(hash.m);
    }
    
    void put(int key, int value) {
        size_t hashed_key = hash(key);
        bool inserted = false;
        for(auto& [k, v] : hash_table[hashed_key]) {
            if(k == key) {
                v = value;
                inserted = true;
                break;
            }
        }
        if(!inserted) hash_table[hashed_key].emplace_back(key, value);
    }
    
    int get(int key) {
        size_t hashed_key = hash(key);
        for(const auto& [k, v] : hash_table[hashed_key]) {
            if(k == key) {
                return v;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        size_t hashed_key = hash(key);
        for (auto it = hash_table[hashed_key].begin(); it != hash_table[hashed_key].end(); ++it){
            if(it->first == key) {
                hash_table[hashed_key].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */