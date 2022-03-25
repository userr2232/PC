class Solution {
    string st;
    
    int read_int(int& i, const string& str) {
        const int n = str.length();
        int sign{1};
        int ans{0};
        int j{i};
        bool read_sign = false;
        for(; j < n; ++j) {
            if(str[j] == '+' || str[j] == ' ') continue;
            else if(str[j] == '-') sign = -sign;
            else break;
        }
        for(; j < n; ++j) {
            if(isdigit(str[j])) ans *= 10, ans += static_cast<int>(str[j]-'0');
            else break;
        }
        while(j < n && str[j] == ' ') ++j;
        i = j;
        return sign > 0 ? ans : -ans;
    }
    
    int evaluate(const string& str) {
        cout << str << endl;
        int i{0};
        int ans{0};
        while(i < str.length()) {
            ans += read_int(i, str);
        }
        return ans;
    }
    
public:
    int calculate(string s) {
        for(auto c : s) {
            if(c == ')') {
                string str = "";
                while(st.back() != '(') {
                    auto c = st.back();
                    st.pop_back();
                    str += c;
                }
                st.pop_back();
                reverse(str.begin(), str.end());
                str = to_string(evaluate(str));
                st += str;
            }
            else st += c;
        }
        return evaluate(st);
    }
};