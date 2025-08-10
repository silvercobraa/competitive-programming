import sys

line = sys.stdin.readline()
while line:
    N, M = map(int, line.split())
    ans = 0
    for _ in range(int(N)):
        ans += all(map(int, input().split()))
    print(ans)
    line = sys.stdin.readline()