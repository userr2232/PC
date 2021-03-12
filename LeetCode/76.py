class Solution:
    def minWindow(self, s: str, t: str) -> str:
        t_counter = Counter(t)
        s_counter = Counter()
        l, r = 0, 0
        min_window = ""
        if s[r] in t_counter:
            s_counter[s[r]] = 1
        for t_c, num in t_counter.items():
            while (t_c not in s_counter or s_counter[t_c] < num) and r < len(s) - 1:
                r += 1
                if s[r] in t_counter:
                    s_counter[s[r]] += 1
            if s_counter[t_c] < num: return ""
        min_window = s[l:r+1]
        while r < len(s):
            while s[l] not in t_counter or s_counter[s[l]] > t_counter[s[l]]:
                if s[l] in t_counter:
                    s_counter[s[l]] -= 1
                l += 1
            min_window = s[l:r+1] if r - l + 1 < len(min_window) else min_window
            r += 1
            if r < len(s) and s[r] in t_counter:
                s_counter[s[r]] += 1
        return min_window