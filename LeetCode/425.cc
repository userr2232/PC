class Solution {
    
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int carry{0};
        string res;
        int upper = max(num1.size(), num2.size())+1;
        for(int i = 0; i < upper; ++i) {
            int n1{0}, n2{0};
            if(i < num1.size()) n1 = num1[i] - '0';
            if(i < num2.size()) n2 = num2[i] - '0';
            int s = n1 + n2 + carry;
            if(s >= 10) carry = 1;
            else carry = 0;
            char c = static_cast<char>((s % 10) + '0');
            if(i < upper-1) res += c;
            else if(i == upper-1 && c != '0') res += c;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};