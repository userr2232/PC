class MaxStack {
    map<int, stack<list<int>::iterator>, greater<int>> m;
    list<int> st;
public:
    MaxStack() {
        
    }
    
    void push(int x) {
        m[x].emplace(st.emplace(st.end(), x));
    }
    
    int pop() {
        auto last = prev(st.end());
        auto val = *last;
        auto it = m.find(val);
        it->second.pop();
        if(it->second.empty()) m.erase(val);
        st.erase(last);
        return val;
    }
    
    int top() {
        return st.back();
    }
    
    int peekMax() {
        return m.begin()->first;
    }
    
    int popMax() {
        auto it = m.begin();
        auto max_val = it->first;
        auto st_it = it->second.top();
        it->second.pop();
        if(it->second.empty()) m.erase(it);
        st.erase(st_it);
        return max_val;
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