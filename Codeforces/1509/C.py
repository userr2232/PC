# #include <iostream>
# #include <vector>
# #include <algorithm>
# #include <set>
# #include <map>

# using namespace std;
# typedef vector<long long> vll;

# int n;
# vll v;
# string zeros;
n = None
v = []
mm = dict()
available = None

def dp(rmin, rmax, rsum, available):
    curmin, curmax, cursum = None, None, 3e12
    if not available: return rsum
    x = mm.get((rsum, available))
    if x: return x
    for i in range(n):
        if available[i] == "1":
            available = available[:i] + "0" + available[i+1:]
            curmin = min(rmin, v[i])
            curmax = max(rmax, v[i])
            cursum = min(cursum, dp(curmin, curmax, rsum+curmax-curmin, available))
            available = available[:i] + "1" + available[i+1:]
    mm[(rsum, available)] = cursum
    return cursum

n = int(input())
available = "1" * n
l = input().strip().split()
v = [int(x) for x in l]
print(dp(3e12, 0, 0, available))