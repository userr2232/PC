class Solution {
    map<int,map<string,int>> transitions {
        {1, {{"+", 2}, {"-", 2}, {"digit", 3}, {".", 5}, {"0", 9}}},
        {2, {{"digit", 3}, {".", 5}, {"0", 9}}},
        {3, {{"digit", 3}, {".", 4}, {"e", 6}, {"E", 6}}},
        {4, {{"digit", 8}, {"e", 6}, {"E", 6}}},
        {5, {{"digit", 8}, {"digit", 3}}},
        {6, {{"digit", 7}}},
        {7, {{"digit", 7}}},
        {8, {{"digit", 8}, {"e", 6}, {"E", 6}}},
        {9, {{".", 4}}}
    };
    
public:
    bool isNumber(string s) {
        int state{1};
        for(const auto& c : s) {
            string action;
            if(c == '+' || c == '-' || c == '.' || c == 'e' || c == 'E') action += c;
            else if(isdigit(c)) {
                if(c == '0') action += c;
                else action = "digit";
            }
            else action += c;
            auto it = transitions[state].find(action);
            if(it == transitions[state].end()) return false;
            state = it->second;
        }
        return (state == 3 || state == 4 || state == 7 || state == 8 || state == 9);
    }
};