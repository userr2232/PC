class MaxStack {   
    map<int,stack<list<int>::iterator>> m;
    list<int> l;
public:
    MaxStack() {
        
    }
    
    void push(int x) {
        auto it = l.insert(l.end(), x);
        m[-x].emplace(it);
    }
    
    int pop() {
        int x = *l.rbegin();
        auto to_erase = m[-x].top();
        m[-x].pop();
        if(m[-x].empty()) m.erase(-x);
        l.erase(to_erase);
        return x;
    }
    
    int top() {
        return l.back();
    }
    
    int peekMax() {
        auto it = m.begin();
        return -(it->first);
    }
    
    int popMax() {
        auto it = m.begin();
        int x = it->first;
        auto st = it->second;
        auto to_erase = st.top();
        m[x].pop();
        if(m[x].empty()) m.erase(x);
        l.erase(to_erase);
        return -x;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */