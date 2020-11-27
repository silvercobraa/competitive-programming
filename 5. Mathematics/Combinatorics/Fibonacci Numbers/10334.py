import sys

fib = [0 for i in range(1000+1)]
fib[0] = 1
fib[1] = 2
for i in range(2, 1000+1):
    fib[i] = fib[i-1] + fib[i-2]

for line in sys.stdin:
    print(fib[int(line)])
