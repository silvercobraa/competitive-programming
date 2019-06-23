import sys
import math

for line in sys.stdin:
    n = int(line)
    if n == 0:
        break
    root = math.ceil(math.sqrt(n))
    diff = root*root - n
    if root % 2 == 0:
        x = root
        y = 1
        y_offset = min(root-1, diff)
        y += y_offset
        diff -= y_offset
        x -= diff

    else:
        y = root
        x = 1
        x_offset = min(root-1, diff)
        x += x_offset
        diff -= x_offset
        y -= diff

    print(x, y)
