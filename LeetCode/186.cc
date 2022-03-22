class Solution {
    void add_word(stack<char>& st, vector<char>& other) {
        if(!st.empty()) {
            if(!other.empty()) other.emplace_back(' ');
            while(!st.empty()) {
                char c = st.top();
                st.pop();
                other.emplace_back(c);
            }
        }
    }
    
public:
    void reverseWords(vector<char>& s) {
        stack<char> st;
        vector<char> other;
        while(!s.empty()) {
            char c = s.back();
            if(c == ' ') {
                add_word(st, other);
            }
            else {
                st.emplace(c);
            }
            s.pop_back();
        }
        add_word(st, other);
        s = other;
    }
};