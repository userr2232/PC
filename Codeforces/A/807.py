import sys

n = int(input())

ratings = []

out = False

for line in sys.stdin.readlines():
    r1, r2 = (map(int, line.split()))
    if r1 != r2:
        print("rated")
        out = True
        break
    else:
        ratings.append((r1,r2))
if not out:
    r_copy = ratings.copy()
    ratings = sorted(ratings, reverse=True)
    print("maybe" if ratings == r_copy else "unrated")
