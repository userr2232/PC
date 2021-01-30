r = lambda : input().strip()
cmps = [ r(), r(), r() ]
d = { 'A': 0, 'B': 0, 'C': 0 }
for cmp in cmps:
    if cmp[1] == '<':
        d[cmp[0]] += 1
    else:
        d[cmp[2]] += 1
s = set()
l = [ None ] * 3
for k, v in d.items():
    s.add(v)
    l[-v - 1] = k
print(''.join(c for c in l) if len(s) == 3 else "Impossible")