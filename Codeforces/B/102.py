l = [*map(int, input().strip())]

count = 0
while len(l) > 1:
    count += 1
    s = 0
    for d in l:
        s += d
    l = [*map(int, str(s))]

print(count)