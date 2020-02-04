import sys

def degree(s):
    # print(s)
    n = int(s)
    if n == 9: return 0
    elif n < 9: return -1
    deg = degree(str(sum(int(c) for c in s)))
    return deg + 1 if deg != -1 else -1

for line in sys.stdin:
    s = line.strip()
    if s == '0': break
    d = degree(s)
    print(s, end=' ')
    if s == '9':
        d += 1
    if d != -1:
        print('is a multiple of 9 and has 9-degree ' + str(d) + '.')
    else:
        print('is not a multiple of 9.')
