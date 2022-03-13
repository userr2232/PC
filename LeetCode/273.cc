class Solution {
    unordered_map<int,string> m = {
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"},
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"},
        {20, "Twenty"},
        {30, "Thirty"},
        {40, "Forty"},
        {50, "Fifty"},
        {60, "Sixty"},
        {70, "Seventy"},
        {80, "Eighty"},
        {90, "Ninety"},
        {100, "Hundred"},
        {1000, "Thousand"},
        {1000000, "Million"},
        {1000000000, "Billion"}
    };
    
    vector<int> partition(int num) {
        if(num == 0) return {};
        vector<int> ans;
        int count{0};
        while(num) {
            ans.emplace_back(num % 1000);
            num /= 1000;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    string interpret(int num, int groups_to_right = 0) {
        string ans;
        if(num / 10 == 0) {
            ans = m[num];
        }
        else if(num / 100 == 0) {
            if(m.count(num)) {
                ans = m[num];
            }
            else {
                ans = m[num / 10 * 10];
                if(num % 10) ans += " " + m[num % 10];   
            }
        }
        else {
            ans = m[num / 100];
            ans += " " + m[100];
            if(num%100) ans += " " + interpret(num%100, 0);
        }
        if(groups_to_right) ans += " " + m[pow(1000, groups_to_right)];
        return ans;
    }
    
public:
    string numberToWords(int num) {
        vector<int> groups = partition(num);
        if(groups.empty()) return "Zero";
        string ans;
        for(int i = 0; i < groups.size(); ++i) {
            if(groups[i] == 0) continue;
            if(i) ans += " ";
            ans += interpret(groups[i], groups.size()-1-i);
        }
        return ans;
    }
};