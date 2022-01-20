class Solution {
    int N, target;
    vector<string> ans;
    
    void recursion(string& num, int idx, long long value, long long prev_operand, long long cur_operand, string& str_operand, string expression) {
        if(idx == num.size()) {
            if(value == target && cur_operand == 0) {
                ans.emplace_back(move(expression));
            }
            return;
        }
        cur_operand = cur_operand*10 + static_cast<long long>(num[idx]-'0');
        str_operand += num[idx];
        string tmp;
        if(cur_operand > 0) recursion(num, idx+1, value, prev_operand, cur_operand, str_operand, expression);
        if(expression == "") recursion(num, idx+1, cur_operand, cur_operand, 0, tmp, str_operand);
        else {
            recursion(num, idx+1, value+cur_operand, cur_operand, 0, tmp, expression+"+"+str_operand);
            recursion(num, idx+1, value-cur_operand, -cur_operand, 0, tmp, expression+"-"+str_operand);
            recursion(num, idx+1, value-prev_operand+prev_operand*cur_operand, prev_operand*cur_operand, 0, tmp, expression+"*"+str_operand);
        }
        str_operand.pop_back();
    }
    
public:
    vector<string> addOperators(string num, int target) {
        this->target = target;
        string str_operand;
        recursion(num, 0, 0, 0, 0, str_operand, "");
        return ans;
    }
};