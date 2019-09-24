import sys

ans = [0 for i in range(250+1)]
ans[0] = 1 # meh
ans[1] = 1
ans[2] = 3

for i in range(3, 250+1):
    ans[i] = ans[i-1] + 2*ans[i-2]

for line in sys.stdin:
    print(ans[int(line)])
