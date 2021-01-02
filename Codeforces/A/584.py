import sys

a, b = (map(int, input().split()))
def count_digits(b):
    digits = 0
    while b:
        b //= 10
        digits += 1
    return digits
d = count_digits(b)
if d > a:
    print(-1)
else:
    print(str(b) + "0" * (a - d))