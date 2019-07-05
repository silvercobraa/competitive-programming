import sys
for line in sys.stdin:
    n, k = map(int, line.split())
    ans = 1
    for i in range(k):
        # print(n - i, i + 1)
        ans *= n - i
        ans //= i + 1
        # print(ans)
    print(len(str(ans)))
