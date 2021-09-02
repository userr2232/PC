class Solution {
    int currentNumber{0}, sign{1};
    char operation = '+';
    bool pushed = true;
    stack<int> st;
    
    void push() {
        st.push(sign*currentNumber);
        sign = 1, currentNumber = 0;
        if(operation != '+') {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            st.push(operation == '*' ? op1*op2 : op2/op1);
        }
        pushed = true;
    }
    
public:
    
    int calculate(string s) {
        for(int i = 0; i < s.length(); ++i) {
            pushed = false;
            char c = s[i];
            if(isdigit(c)) {
                currentNumber *= 10;
                currentNumber += c-'0';
            }
            else if(c == '+') push(), operation = '+';
            else if(c == '-') push(), sign = -1, operation = '+';
            else if(c == '*') push(), operation = '*';
            else if(c == '/') push(), operation = '/';
            if(i == s.length()-1 && !pushed) push();
        }
        int ans{0};
        while(!st.empty()) ans += st.top(), st.pop();
        return ans;
    }
    
};