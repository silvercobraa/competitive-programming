import sys

def egcd(a, b):
    if b == 0: return 1, 0, a
    x, y, g = egcd(b, a % b)
    return y, x - (a//b)*y, g


for line in sys.stdin:
    a, b = map(int, line.split())
    print(*egcd(a, b))
