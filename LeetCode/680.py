class Solution:
    def remove_one(self, s: str) -> (str, str):
        l = len(s)
        for i in range(l):
            i, j = i, l - 1 - i
            if i == j: return None, None
            if s[i] != s[j]:
                return s[:i] + s[i+1:], s[:j] + s[j+1:]
        return None, None
                
    def check_pal(self, s) -> bool:
        l = len(s)
        if l % 2:
            return s[:l//2] == s[l//2+1:][::-1]
        return s[:l//2] == s[l//2:][::-1]
    
    def validPalindrome(self, s: str) -> bool:
        if len(s) <= 1: return True
        s1, s2 = self.remove_one(s)
        print(s1, s2)
        if s1 and s2:
            return self.check_pal(s1) or self.check_pal(s2)
        return True