class Solution(object):
    def get_last(self, num, i):
        if i >= len(num): return None
        return num[-i - 1]
    
    def get_next(self):
        i = 0
        while True:
            yield self.get_last(self.num1, i), self.get_last(self.num2, i)
            i += 1
    
    def addStrings(self, num1, num2):
        self.num1, self.num2 = num1, num2
        res = ""
        a, b = None, None
        c = 0
        for x in self.get_next():
            s = 0
            if x == (None, None): break
            print(x)
            a, b = x
            if a:
                a = int(a)
                s += a
            if b:
                b = int(b)
                s += b
            s += c
            if s > 9:
                c = 1
                s %= 10
            else: c = 0
            res += str(s)
        if c == 1:
            res += "1"
        return res[::-1]