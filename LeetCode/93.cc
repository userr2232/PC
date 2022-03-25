class Solution {    
    vector<string> partition(const string& s, int j, int k, int l) {
        return {s.substr(0, j), s.substr(j, k-j), s.substr(k, l-k), s.substr(l)};
    }
    
    bool is_valid_num(const string& num) {
        if(num.empty()) return false;
        if(num[0] == '0' && num.size() > 1) return false;
        if(num.length() > 3) return false;
        if(num.length() == 3 && num > "255") return false;
        return true;
    }
    
    void add_to_ans(vector<string>& ans, vector<string>& nums) {
        string str;
        for(int i = 0; i < 4; ++i) {
            if(i) str += ".";
            str += move(nums[i]);
        }
        ans.emplace_back(move(str));
    }
    
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        for(int j = 1; j < s.length(); ++j) for(int k = j+1; k < s.length(); ++k) 
            for(int l = k+1; l < s.length(); ++l) {
                auto nums = partition(s, j, k, l);
                bool valid{true};
                for(const auto& num : nums)
                    if(!is_valid_num(num)) {
                        valid = false;
                        break;
                    }
                if(valid) add_to_ans(ans, nums);
            }
        return ans;
    }
};