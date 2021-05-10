x = input()
s = 0
while True:
    for c in x:
        s += int(c)
    x = str(s)
    if len(x) == 1:
        break
    s = 0
print(s)