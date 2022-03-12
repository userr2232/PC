struct Node {
    int key, value, freq;
    Node(int key, int value, int freq): key{key}, value{value}, freq{freq} {}
};

class LFUCache {
    const int capacity;
    int minfreq{0}, size{0};
    
    unordered_map<int,list<Node>::iterator> key_node;
    unordered_map<int,list<Node>> freq_nodes;
public:
    LFUCache(int capacity): capacity{capacity} {}
        
    void update_freq(int key) {
        auto it = key_node[key];
        auto freq = it->freq;
        it->freq++;
        auto& new_list = freq_nodes[freq+1];
        new_list.splice(new_list.begin(), freq_nodes[freq], it);
        if(freq_nodes[minfreq].empty()) {
            freq_nodes.erase(minfreq);
            minfreq++;
        }
    }
    
    int get(int key) {
        if(auto it = key_node.find(key); it != key_node.end()) {
            update_freq(key);
            return it->second->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;
        if(auto it = key_node.find(key); it != key_node.end()) {
            it->second->value = value;
        }
        else {
            if(size == capacity) {
                auto last = freq_nodes[minfreq].end();
                last = prev(last);
                key_node.erase(last->key);
                freq_nodes[minfreq].erase(last);
            }
            else size++;
            minfreq = 0;
            freq_nodes[0].emplace_front(key, value, 0);
            key_node[key] = freq_nodes[0].begin();
        }
        update_freq(key);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */