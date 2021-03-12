class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        set<int> valid;
        int i = 0;
        for(char c : s) {
            if(c == '(') st.push(i++);
            else if(c == ')') {
                if(!st.empty()) {
                    auto x = st.top();
                    st.pop();
                    valid.insert(x);
                    valid.insert(i);
                }
                i++;
            }
        }
        i = 0;
        string answer = "";
        for(char c : s) {
            if(c == ')' || c == '(') {
                if(valid.count(i++))
                    answer += c;
            }
            else
                answer += c;
        }
        return answer;
    }
};