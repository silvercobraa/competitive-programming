import sys

ans = [0 for i in range(180 + 1)]

minu = 0
hour = 0
for t in range(1, 720 + 1):
    minu = (minu + 1) % 60
    if t % 12 == 0:
        hour = (hour + 1) % 60
    # print(hour, minu)
    d1 = abs(minu - hour)
    d2 = 60 - d1
    d = min(d1, d2)
    ans[6*d] += 1
    # print(6*d)

for s in sys.stdin:
    print('Y' if ans[int(s)] > 0 else 'N')
