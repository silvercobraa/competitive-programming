import sys

def evaluate(coef, x):
    ret = 0
    for c in coef:
        ret *= x
        ret += c
    return ret

coef = None
for i, line in enumerate(sys.stdin):
    if i % 2 == 0:
        coef = list(map(int, line.split()))
    else:
        vals = list(map(int, line.split()))
        ans = [evaluate(coef, val) for val in vals]
        print(*ans)
