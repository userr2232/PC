digits = [*map(int, [*input().strip()])]
min_digits = [min(d, 9 - d) for d in digits]
s = ''.join(str(d) for d in min_digits)
if s[0] == '0':
    s = '9' + s[1:]
print(s)