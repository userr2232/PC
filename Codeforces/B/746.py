n, w = int(input()), input()
res = ''
for idx, c in enumerate(w):
    if (n - idx) % 2:
        res = res + c
    else:
        res = c + res
print(res)