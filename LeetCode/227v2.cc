class Solution {
    pair<int,char> read_int_and_operator(const string& s, int& i) {
        int current{0}, sign{1};
        char op = '+';
        for(; i < s.length(); ++i) {
            if(s[i] == ' ') continue;
            else break;
        }
        if(i == s.length()) return {current*sign, op};
        if(s[i] == '+') {}
        else if(s[i] == '-') sign = -1;
        else if(s[i] == '*') op = '*';
        else if(s[i] == '/') op = '/';
        else {
            current += s[i]-'0';
        }
        ++i;
        for(; i < s.length(); ++i) {
            if(isdigit(s[i])) current *= 10, current += s[i]-'0';
            else if(s[i] == ' ') continue;
            else {
                --i;
                break;
            }
        }
        return {current*sign, op};
    }
    
public:
    int calculate(string s) {
        int buffer{0}, ans{0};
        bool empty_buffer{true};
        for(int i = 0; i < s.length(); ++i) {
            auto [num, op] = read_int_and_operator(s, i);
            switch(op) {
                case '+':
                    if(empty_buffer) empty_buffer = false;
                    else ans += buffer;
                    buffer = num;
                    break;
                case '*':
                    buffer *= num;
                    break;
                case '/':
                    buffer /= num;
                    break;
                default:
                    cout << "WHAT!?" << endl;
            }
        }
        if(!empty_buffer) ans += buffer;
        return ans;
    }
};