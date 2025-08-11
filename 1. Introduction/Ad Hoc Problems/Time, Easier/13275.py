T = int(input())

def is_leap(y):
    return y % 4 == 0 and y % 100 != 0 or y % 400 == 0

for t in range(1, T+1):
    D, M, Y, QY = map(int, input().split())
    if D == 29 and M == 2:
        ans = sum(1 for y in range(Y + 4, QY + 1, 4) if is_leap(y))
        print("Case %d: %d" % (t, ans))

    else:
        print("Case %d: %d" % (t, QY - Y))
