class RandomizedSet {
    unordered_set<int> s;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        return s.size() < (s.insert(val), s.size());
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        return s.size() > (s.erase(val), s.size());
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(0,max(0,(int)s.size()-1));
        return *next(s.begin(), (int)distrib(gen));
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */