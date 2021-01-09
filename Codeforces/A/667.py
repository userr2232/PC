import sys
import math

d, h, v, e = (map(float, input().strip().split()))

if not h:
    print("YES\n0")
else:
    drink_speed = v / (math.pi * d ** 2 / 4)
    if drink_speed < e:
        print("NO")
    else:
        print(f"YES\n{h / -(e - drink_speed)}")