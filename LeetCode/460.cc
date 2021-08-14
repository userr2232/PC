struct Node {
    int key;
    int value;
    int freq;
    list<Node*>::iterator it;
};

class LFUCache{
private:
    int capacity;
    int minFreq;
    unordered_map<int,Node*> nodes;
    unordered_map<int,list<Node*>> caches;
    
    bool exists(int key) {
        return nodes.count(key);
    }
    
    void update_freq(Node* node) {
        int& freq = node->freq;
        erase_from_list(node);
        freq++;
        auto& new_cache = caches[freq];
        new_cache.push_back(node);
        node->it = --new_cache.end();
        if(caches.count(minFreq) == 0) minFreq++;
    }
    
    void erase_from_list(Node* node) {
        int freq = node->freq;
        auto& old_cache = caches[freq];
        old_cache.erase(node->it);
        if(old_cache.empty()) caches.erase(freq);
    }
    
    void erase_acc_policy() {
        auto& cache = caches[minFreq];
        auto node = *cache.begin();
        nodes.erase(node->key);
        erase_from_list(node);
        delete node;
        node = nullptr;
    }
    
public:
    LFUCache(int capacity): capacity{capacity} {}
    
    int get(int key) {
        if(exists(key)) {
            auto node = nodes[key];
            update_freq(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(capacity <= 0) return;
        if(exists(key)) {
            auto node = nodes[key];
            node->value = value;
            update_freq(node);
        }
        else {
            if(nodes.size() == capacity) erase_acc_policy();
            int freq = 1;
            minFreq = freq;
            Node* node = new Node{key, value, freq};
            nodes[key] = node;
            auto& new_cache = caches[freq];
            new_cache.push_back(node);
            node->it = --new_cache.end();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */