class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto&& c : s) {
            if(c == ')' || c == '}' || c == ']') {
                char&& prev = c == ')' ? '(' : c == '}' ? '{' : '[';
                if(st.empty() || st.top() != prev) return false;
                else st.pop();
            }
            else st.emplace(c);
        }
        return st.empty();
    }
};