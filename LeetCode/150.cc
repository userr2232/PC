class Solution {
    int parse_int(const string& str) {
        int sign{1};
        int i = 0;
        const int n = str.length();
        for(; i < n; ++i) {
            if(str[i] == '-') sign = -sign;
            else break;
        }
        int num{0};
        for(; i < n; ++i) {
            num *= 10;
            num += static_cast<int>(str[i]-'0');
        }
        return sign == 1 ? num : -num;
    }
    
    string evaluate(const string& a, const string& b, const string& op) {
        auto a_int = parse_int(a);
        auto b_int = parse_int(b);
        int result;
        switch(op[0]) {
            case '+':
                result = a_int + b_int;
                break;
            case '-':
                result = a_int - b_int;
                break;
            case '*':
                result = a_int * b_int;
                break;
            case '/':
                result = a_int / b_int;
                break;
            default:
                cout << "THIS SHOULD NOT HAPPEN" << endl;
                break;
        }
        return to_string(result);
    }
    
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(auto& token : tokens) {
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                auto b = st.top();
                st.pop();
                auto a = st.top();
                st.pop();
                st.emplace(evaluate(a, b, token));
            }
            else {
                st.emplace(move(token));
            }
        }
        return stoi(st.top());
    }
};