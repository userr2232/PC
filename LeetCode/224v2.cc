class Solution {
    void emplace(vector<int>& v, int& x, bool& valid, int& counter) {
        if(!valid) return;
        if(counter & 1) x = -x;
        counter = 0;
        v.emplace_back(move(x));
        x = 0;
        valid = false;
    }
    
    vector<int> parse(const string& s) {
        const int n = s.length();
        vector<int> ans;
        bool valid = false;
        int current{0};
        int counter{0};
        int leftparen{0};
        int j;
        for(int i = 0; i < n; ++i) {
            char c = s[i];
            switch(c) {
                case '+':
                    emplace(ans, current, valid, counter);
                    break;
                case '-':
                    emplace(ans, current, valid, counter);
                    counter++;
                    break;
                case '(':
                    j = i;
                    for(; j < n; ++j) {
                        if(s[j] == '(') leftparen++;
                        else if(s[j] == ')') leftparen--;
                        if(leftparen == 0) { 
                            current = calculate(s.substr(i+1, j-i-1));
                            valid = true;
                            emplace(ans, current, valid, counter);
                            break;
                        }
                    }
                    i = j;
                    break;
                case ' ':
                    emplace(ans, current, valid, counter);
                    break;
                default:
                    valid = true;
                    current *= 10;
                    current += c - '0';
                    break;
            }
            if(i == n-1)
                emplace(ans, current, valid, counter);
        }
        return ans;
    }
    
public:
    int calculate(string s) {
        auto operands = parse(s);
        return accumulate(operands.begin(), operands.end(), 0);
    }
};