n = int(input())
for i in range(n):
    v = list(map(int, input().split()))
    v.sort()
    print('Case ' + str(i+1), end=': ')
    if v[0] <= 0 or v[1] <= 0 or v[2] <= 0 or v[0]+v[1] <= v[2]:
        print('Invalid')
    elif v[0] == v[1] and v[1] == v[2]:
        print('Equilateral')
    elif v[0] == v[1] or v[1] == v[2]:
        print('Isosceles')
    else:
        print('Scalene')
