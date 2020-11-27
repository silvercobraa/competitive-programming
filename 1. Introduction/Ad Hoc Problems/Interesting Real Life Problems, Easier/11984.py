n = int(input())

for i in range(n):
    c, d = map(int, input().split())
    print('Case %i: %.2f' % (i + 1, c + 5*d/9))
