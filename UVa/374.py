def mod_pow(b, e, mod):
    if mod == 1: return 0
    if e == 1: return b
    if e == 0: return 1
    half = mod_pow(b, e // 2, mod)
    if e % 2:
        return (((half * half) % mod) * b) % mod
    else:
        return (half * half) % mod

def readinput():
    l = input()
    if not len(l.strip()): return readinput()
    return (map(int, (l, input(), input())))

while True:
   try:
      b, e, mod = readinput()
      print(mod_pow(b, e, mod))
   except EOFError:
      break