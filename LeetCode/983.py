class Solution:            
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        n = len(days)
        memo = dict()
        def DP(i):
            nonlocal days, costs, n, memo
            if i >= n: return 0
            val = memo.get(i)
            if val: return val
            plus30 = plus7 = 1
            current_day = days[i]
            while i + plus7 < n and days[i+plus7] < current_day + 7:
                plus7 += 1
            while i + plus30 < n and days[i+plus30] < current_day + 30:
                plus30 += 1
            res = memo[i] = min(costs[0] + DP(i+1), min(costs[1] + DP(i+plus7), costs[2] + DP(i+plus30)))
            return res
        return DP(0)