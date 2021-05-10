from collections import Counter

def solve():
    s = input()
    counter = Counter(s)
    c = 0
    m = 0
    l = None
    ans = ""
    for k, v in counter.items():
        if v % 2:
            c += 1
            m = v
            l = k
    if len(s) % 2:
        if c != 1:
            print("NO SOLUTION")
            return
        else:
            for k, v in counter.items():
                if v % 2 == 0:
                    ans += k * (v//2)
            print(ans + l * m + ans[::-1])
    elif c > 0:
        print("NO SOLUTION")
        return
    else:
        for k, v in counter.items():
            ans += k * (v//2)
        print(ans + ans[::-1])

solve()