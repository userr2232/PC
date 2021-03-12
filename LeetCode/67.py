class Solution:
    def addBinary(self, a: str, b: str) -> str:
        a, b = a[::-1], b[::-1]
        i = 0
        c = 0
        ans = ""
        while i < len(a) or i < len(b):
            s = 0
            s += c
            c = 0
            if i < len(a):
                s += int(a[i])
            if i < len(b):
                s += int(b[i])
            if s > 1:
                s %= 2
                c = 1
            ans += str(s)
            i += 1
        if c == 1:
            ans += str(c)
        return ans[::-1]