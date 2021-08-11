class Solution {
    stack<char> st;
public:
    int readint(string& s) {
        int ans{0}, n = s.size(), i{0};
        int sign{1};
        for(; i < n; ++i) {
            char c = s[i];
            if(c == '-') sign *= -1;
            else if(c == '+' || c == ' ') continue;
            else break;
        }
        for(; i < n; ++i) {
            char c = s[i];
            if(isdigit(c)) {
                ans *= 10;
                ans += c - '0';
            }
            else break;
        }
        s = s.substr(i);
        return sign*ans;
    }
    
    int evaluate(string s) {
        int ans{0};
        while(!s.empty()) ans += readint(s);
        return ans;
    }
        
    int calculate(string s) {
        for(char c: s) {
            cout << c;
            if(c == ')') {
                string k = "";
                while(st.top() != '(') {
                    char t = st.top();
                    k += t;
                    st.pop();
                }
                st.pop();
                reverse(k.begin(), k.end());
                int result = evaluate(k);
                for(char x : to_string(result)) st.push(x);
            }
            else st.push(c);
        }
        string k = "";
        while(!st.empty()) {
            k += st.top();
            st.pop();
        }
        reverse(k.begin(), k.end());
        return evaluate(k);
    }
};