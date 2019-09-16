import sys
import math

case = 1
for line in sys.stdin:
    n = int(line)
    if n < 0:
        break
    ans = 1
    is_power2 = True
    while n != 1:
        if n % 2 == 1:
            is_power2 = False
        n //= 2
        ans += 1
    if is_power2:
        ans -= 1
    print('Case %d: %d' % (case, ans))
    case += 1
