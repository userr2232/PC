class Solution:
    def gen_dict(self, order):
        self.d = {}
        for idx, x in enumerate(order):
            self.d[x] = idx
    
    def check(self, s1, s2, order):
        l = min(len(s1), len(s2))
        for i in range(l):
            if self.d[s1[i]] < self.d[s2[i]]:
                return True
            elif self.d[s1[i]] > self.d[s2[i]]:
                return False
        if len(s1) > len(s2):
            return False
        return True
    
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        self.gen_dict(order)
        for i in range(len(words) - 1):
            word1, word2 = words[i], words[i+1]
            if not self.check(word1, word2, order):
                return False
        return True