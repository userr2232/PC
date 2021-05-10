from collections import Counter

s = input()
t = input()

def is_subsequence(t, s):
    start = 0
    for i, ct in enumerate(t):
        found = False
        for si in range(start, len(s)):
            if s[si] == ct:
                found = True
                start = si + 1
                break
        if not found or start == len(s) and i < len(t) - 1:
            return False
    return True        

def are_anagrams(t, s):
    c1, c2 = Counter(s), Counter(t)
    return c1 == c2

def is_subset(t, s):
    c1, c2 = Counter(s), Counter(t)
    for k, v in c2.items():
        if not c1[k] or c1[k] < v:
            return False
    return True

if is_subsequence(t, s):
    print("automaton")
elif are_anagrams(t, s):
    print("array")
elif is_subset(t, s):
    print("both")
else:
    print("need tree")