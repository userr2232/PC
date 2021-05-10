t = int(input())
while t:
    t -= 1
    n, m = map(int, input().strip().split())
    s = str(n)
    i = 0
    while i < m:
        i += 1
        s = ''.join(str(int(x) + 1) for x in s)
    print(len(s) % int(1e9 + 7))