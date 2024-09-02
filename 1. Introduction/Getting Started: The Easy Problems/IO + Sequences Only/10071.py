import sys

for line in sys.stdin:
    v, t = map(lambda x: int(x.strip()), line.strip().split())
    print(2 * t * v)
