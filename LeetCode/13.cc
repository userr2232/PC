class Solution {
public:
    int romanToInt(string s) {
        int ans{0};
        for(auto it = s.begin(); it != s.end(); ++it) {
            char c = *it;
            switch(c) {
                case 'I':
                    if(auto next_it = next(it); next_it != s.end() && *next_it == 'V' || *next_it == 'X') {
                        if(*next_it == 'V') ans += 4;
                        else if(*next_it == 'X') ans += 9;
                        it = next_it;
                    }
                    else ans += 1;
                    break;
                case 'V':
                    ans += 5;
                    break;
                case 'X':
                    if(auto next_it = next(it); next_it != s.end() && *next_it == 'L' || *next_it == 'C') {
                        if(*next_it == 'L') ans += 40;
                        else if(*next_it == 'C') ans += 90;
                        it = next_it;
                    }
                    else ans += 10;
                    break;
                case 'L':
                    ans += 50;
                    break;
                case 'C':
                    if(auto next_it = next(it); next_it != s.end() && *next_it == 'D' || *next_it == 'M') {
                        if(*next_it == 'D') ans += 400;
                        else if(*next_it == 'M') ans += 900;
                        it = next_it;
                    }
                    else ans += 100;
                    break;
                case 'D':
                    ans += 500;
                    break;
                case 'M':
                    ans += 1000;
                    break;
            }
        }
        return ans;
    }
};