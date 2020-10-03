import sys

def upper_bound(x):
    count = 100000 - 1 # tenia un off-by-one con 99999
    first = 1
    while count > 0:
        it = first
        step = count//2
        it += 2*step;
        if not (x <= it**2):
            first = it + 2
            count -= step + 1
        else:
            count = step
    return first-1, first**2


for line in sys.stdin:
    n, x = map(int, line.split())
    if n == 0 and x == 0:
        break
    row, col = n//2+1, n//2+1
    # upper = 1
    # side = 0
    # while upper < x:
    #     side += 2
    #     upper = (side+1)**2
    side, upper = upper_bound(x)
    # print(side, upper)
    row += side//2
    col += side//2
    diff = upper - x
    # print(n, x, side, upper, diff)
    if diff > 0:
        row -= min(side, diff)
        diff -= side
    if diff > 0:
        col -= min(side, diff)
        diff -= side
    if diff > 0:
        row += min(side, diff)
        diff -= side
    if diff > 0:
        col += min(side, diff)
        diff -= side
    print('Line = %d, column = %d.' % (row, col))
