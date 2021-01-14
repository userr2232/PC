l, r = map(lambda s : s.strip(), input().split("|"))
o = input().strip()
ll, lr, lo = len(l), len(r), len(o)
s = ll + lr + lo
if s % 2 == 0 and max(ll, lr) <= s // 2:
    o_l = s // 2 - ll
    print(f"{l + o[:o_l]}|{r + o[o_l:]}")
else:
    print("Impossible")