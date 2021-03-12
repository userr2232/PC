class Solution:    
    def isMatch(self, s: str, p: str) -> bool:
        memo = dict()
        ns, np = len(s), len(p)
        def DP(i, j):
            nonlocal s, p, ns, np
            if j >= np: return i >= ns
            val = memo.get((i, j))
            if val is not None:
                return val
            left_match = i < ns and p[j] in {s[i], '.'}
            if j <= np - 2 and p[j+1] == '*':
                res = memo[(i, j)] = left_match and DP(i+1, j) or DP(i, j+2)
                return res
            else:
                res = memo[(i, j)] = left_match and DP(i+1, j+1)
                return res
        return DP(0, 0)