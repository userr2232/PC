class Solution:
    def DP(self, i, j):
        self.called.add((i, j))
        if i > j: return
        if self.s[i:j] in self.better_dict:
            self.starts_with[i].add((i,j))
        for m in range(i, j):
            if (i, m) not in self.called:
                self.DP(i, m)
            if (m, j) not in self.called:
                self.DP(m, j)
                
    def add_answer(self, l):
        res = []
        for tup in l:
            res.append(self.s[tup[0]:tup[1]])
        self.answer.append(' '.join(res))
    
    def DFS(self, current, l):
        _, end = current
        l.append(current)
        if end == self.n:
            self.add_answer(l)
            return
        for neighbor in self.starts_with[end]:
            before = l[:]
            self.DFS(neighbor, l)
            l = before
        self.visited.add(current)
        
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        self.better_dict = set(wordDict)
        self.s = s
        self.called = set()
        self.starts_with = defaultdict(set)
        self.n = len(s)
        self.DP(0, self.n)
        self.visited = set()
        print(self.starts_with)
        self.answer = []
        for tup in self.starts_with[0]:
            self.DFS(tup, [])
        return self.answer