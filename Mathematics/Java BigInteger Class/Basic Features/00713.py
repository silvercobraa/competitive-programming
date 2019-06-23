n = int(input())
for i in range(n):
    a, b = input().split()
    a = int(a[::-1])
    b = int(b[::-1])
    c = a+b
    c = str(c)[::-1]
    print(int(c))
