import sys

def ans(n, a):
    return sum((i*a**i for i in range(1, n+1)))

for line in sys.stdin:
    n, a = map(int, line.split())
    print(ans(n, a))
