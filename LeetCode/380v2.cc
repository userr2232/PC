class RandomizedSet {
    struct Entry {
        int value, index;
        Entry(int value, int index): value{value}, index{index} {}
    };
    
    struct EntryHash {
        size_t operator()(unique_ptr<Entry> const& ptr) const {
            return hash<int>()(ptr->value);
        }
    };
    
    struct EntryEqual {
        bool operator()(unique_ptr<Entry> const& lhs, unique_ptr<Entry> const& rhs) const {
            return lhs->value == rhs->value;
        }
    };
    
    mt19937 engine;
    random_device rd;
    unordered_set<unique_ptr<Entry>,EntryHash,EntryEqual> s;
    vector<Entry*> v;
    
public:
    RandomizedSet() {
        engine = mt19937(rd());
    }
    
    bool insert(int val) {
        auto ptr = make_unique<Entry>(val, v.size());
        auto it = s.find(ptr);
        if(it != s.end()) return false;
        v.emplace_back(ptr.get());
        s.emplace(move(ptr));
        return true;
    }
    
    bool remove(int val) {
        auto ptr = make_unique<Entry>(val, v.size());
        auto it = s.find(ptr);
        if(it == s.end()) return false;
        auto index = (*it)->index;
        if(index + 1 != v.size()) {
            auto&& back = v.back();
            back->index = index;
            v[index] = back;
        }
        v.pop_back();
        s.erase(it);
        return true;
    }
    
    int getRandom() {
        uniform_int_distribution<int> dist(0, static_cast<int>(v.size())-1);
        return v[dist(engine)]->value;
    }
};