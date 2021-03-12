class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        N, res = len(num), []
        def recursion(idx, prev_operand, cur_operand, value, path):
            if idx == N:
                if cur_operand == 0 and value == target:
                    res.append(path)
                return
            
            cur_operand = cur_operand * 10 + int(num[idx])
            str_operand = str(cur_operand)
            
            if cur_operand > 0:
                recursion(idx + 1, prev_operand, cur_operand, value, path)
            
            if path:
                recursion(idx + 1, cur_operand, 0, value + cur_operand, path + "+" + str_operand)
            else:
                recursion(idx + 1, cur_operand, 0, value + cur_operand, str_operand)
                return
            
            recursion(idx + 1, -cur_operand, 0, value - cur_operand, path + "-" + str_operand)
            
            value = value - prev_operand + (cur_operand * prev_operand)
            recursion(idx + 1, cur_operand * prev_operand, 0, value, path + "*" + str_operand)
            
        recursion(0, 0, 0, 0, "")
        return res