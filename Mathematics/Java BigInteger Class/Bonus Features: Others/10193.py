n = int(input())

def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)

for i in range(n):
    s1 = input()
    s2 = input()
    n1 = 0
    n2 = 0
    for c in s1:
        n1 = 2*n1 + int(c)
    for c in s2:
        n2 = 2*n2 + int(c)
    g = gcd(n1, n2)
    # print(g)
    if g != 1:
        print('Pair #%d: All you need is love!' % (i+1))
    else:
        print('Pair #%d: Love is not all you need!' % (i+1))
