def solve():
    def readinput():
        return map(int, input().strip().split())
    r1, r2 = readinput()
    c1, c2 = readinput()
    d1, d2 = readinput()
    for g1 in range(1, 10):
        for g2 in range(1, 10):
            for g3 in range(1, 10):
                for g4 in range(1, 10):
                    s = set([g1, g2, g3, g4])
                    if len(s) == 4:
                        if r1 == g1 + g2 and r2 == g3 + g4 and c1 == g1 + g3 and c2 == g2 + g4 and d1 == g1 + g4 and d2 == g2 + g3:
                            return f"{g1} {g2}\n{g3} {g4}"
    return -1
print(solve())