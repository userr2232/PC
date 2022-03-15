class MaxStack {
    multiset<int> s;
    stack<multiset<int>::iterator> st;
    
public:
    MaxStack() {
        
    }
    
    void push(int x) {
        st.emplace(s.insert(-x));
    }
    
    int pop() {
        auto it = st.top();
        st.pop();
        int x = *it;
        s.erase(it);
        return -x;
    }
    
    int top() {
        return -*st.top();
    }
    
    int peekMax() {
        return -*s.begin();
    }
    
    int popMax() {
        auto it = s.begin();
        int x = *it;
        stack<multiset<int>::iterator> buffer;
        while(!st.empty() && *st.top() != *it) {
            buffer.emplace(st.top());
            st.pop();
        }
        auto to_erase = st.top();
        st.pop();
        s.erase(to_erase);
        while(!buffer.empty()) {
            st.emplace(buffer.top());
            buffer.pop();
        }
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