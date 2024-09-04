T = int(input())
for t in range(1, T+1):
    N = int(input())
    ans = max(map(int, input().split()))
    print("Case %d: %d" % (t, ans))
