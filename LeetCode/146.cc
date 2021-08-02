struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
};

class LRUCache {
    unordered_map<int,Node*> cache;
    Node* head, *tail;
    int capacity;
    
    void move_to_end(int key) {
        Node* node = cache[key];
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
        Node* last = tail->prev;
        last->next = node;
        node->prev = last;
        node->next = tail;
        tail->prev = node;
    }
    
    void add(int key, int value) {
        Node* node = new Node{key, value, nullptr, nullptr};
        Node* last = tail->prev;
        last->next = node;
        node->prev = last;
        node->next = tail;
        tail->prev = node;
        cache[key] = node;
    }
    
    void evict_and_add(int key, int value) {
        Node* to_evict = head->next;
        cache.erase(to_evict->key);
        Node* second = to_evict->next;
        head->next = second;
        second->prev = head;
        delete to_evict;
        add(key, value);
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node{-1,-1,nullptr,nullptr};
        tail = new Node{-1,-1,nullptr,nullptr};
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.count(key) == 0) return -1;
        move_to_end(key);
        return cache[key]->value;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;
        if(cache.count(key)) {
            move_to_end(key);
            cache[key]->value = value;
        }
        else {
            if(cache.size() == capacity) evict_and_add(key, value);
            else add(key, value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */