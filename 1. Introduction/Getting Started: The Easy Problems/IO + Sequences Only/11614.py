import math

n = int(input())
for _ in range(n):
    x = int(input().strip())
    root = math.floor(math.sqrt(2*x + 1/4) - 1/2)
    print(root)
