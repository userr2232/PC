class Solution:
    def __init__(self):
        self.d = {}
    
    def valid(self, s):
        if self.d.get(s):
            return self.d[s]
        else:
            test = ''.join([c for c in s if c == ')' or c == '('])
            if len(test) % 2:
                self.d[s] = False
                return False
            st = 0
            for c in s:
                if c == '(':
                    st += 1
                elif c == ")":
                    if st > 0:
                        st -= 1
                    else:
                        self.d[s] = False
                        return False
            if st > 0:
                self.d[s] = False
                return False
            self.d[s] = True
            return True
    
    def removeInvalidParentheses(self, s: str) -> List[str]:
        valid_strs = set()
        visited = set()
        q = []
        removed = -1
        visited.add(s)
        q.append((s, 0))
        while len(q):
            current, level = q[0]
            q = q[1:]
            if removed != -1 and level > removed: break
            if self.valid(current):
                removed = level
                valid_strs.add(current)
                continue
            else:
                for i in range(len(current)):
                    if current[i] != '(' and current[i] != ')': continue
                    x = current[:i] + current[i+1:]
                    if x not in visited:
                        visited.add(x)
                        q.append((x, level + 1))
        return list(valid_strs)