n = int(input())
l = [*map(int, input().strip().split())]

sa, sb = 0, -1
max_length = 1
idx = None
in_wave = False
for idx, c in enumerate(l[1:], 1):
    if c < l[idx - 1]:
        in_wave = True
        sb = idx
    elif in_wave:
        if c >= l[idx - 1]:
            if sb == -1:
                sb = idx - 1
            if c > l[idx - 1]:
                max_length = max(max_length, idx - sa)
                in_wave = False
                sa = sb
                sb = -1

print(max(max_length, idx - sa + 1) if idx else max_length)