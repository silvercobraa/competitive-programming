n = int(input())

for i in range(n):
    hh, mm = map(int, input().split(':'))
    if hh != 6 and hh != 12:
        hh = 12 - hh
    if mm != 0 and mm != 30:
        mm = 60 - mm
    if mm != 0:
        hh -= 1
        if hh == 0:
            hh = 12
    print('%02d:%02d' % (hh, mm))
