s = input()

b = True
for i in range(2, len(s)):
    if (ord(s[i-1]) + ord(s[i-2]) - 2 * ord('A')) % 26 != ord(s[i]) - ord('A'):
        b = False
        break

print("YES" if b else "NO")