import sys

for line in sys.stdin:
    n = int(line)
    if n == 0:
        break
    if (n//10 - 5*(n%10))%17 == 0:
        print('1')
    else:
        print('0')
