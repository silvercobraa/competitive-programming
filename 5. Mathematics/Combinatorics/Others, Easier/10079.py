import sys
for line in sys.stdin:
    n = int(line)
    if n < 0:
        break
    ans = n*(n+1)//2+1
    print(ans)
