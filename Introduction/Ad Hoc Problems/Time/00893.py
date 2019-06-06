# OverflowError :(
import sys
import datetime as dt

case = 1

def isleap(y):
    return y%4==0 and (not (y%100==0)) or y%400==0

def leaps(y):
    return y//4 - y//100 + y//400


monthdays = [0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28]

for i in range(1, len(monthdays)):
    monthdays[i] += monthdays[i - 1]

def date2days(y, m, d):
    yy = y
    yy -= 1 if m == 1 or m == 2 else 0
    ans = yy*365 + leaps(yy) + monthdays[(m + 9)%12] + d - 1
    return ans

def days2date(days):
    cycle400 = 365*400 + 100 - 3
    cycle100 = 365*100 + 25 - 1
    cycle4 = 365*4 + 1
    cycle1 = 365
    y400 = days // cycle400
    days = days % cycle400
    flag3 = days == 0
    y100 = days // cycle100
    days = days % cycle100
    flag2 = days == 0
    y4 = days // cycle4
    days = days % cycle4
    flag1 = days == 0
    y1 = days // cycle1
    days = days % cycle1
    y = 400*y400 + 100*y100 + 4*y4 + y1
    m = 0
    for i in range(1, len(monthdays)):
        if days < monthdays[i]:
            days = days - monthdays[i - 1] + 1
            break
        m += 1
    m = (m + 2) % 12 + 1
    if m == 1 or m == 2:
        y += 1

    flags = (flag1 and not flag2) or flag3
    # flags = not((flag1 and flag2 and not flag3) or (not flag1 and not flag2 and not flag3))
    # print('flags:', flag1, flag2, flag3, ' ', flags, 'leap:', isleap(y))
    if m == 3 and days == 1 and isleap(y) and not flags:
        days = 29
        m = 2
    print(days, m, y)
    return days, m, y

for line in sys.stdin:
    n, d, m, y = map(int, line.split())
    case += 1
    if n == 0 and d == 0 and m == 0 and y == 0:
        break

    days = date2days(y, m, d)
    # print(d, m, y, ':')
    # dd, mm, yy = days2date(days)
    # if d != dd or m != mm or y != yy:
    #     print(d, m, y, ' ', dd, mm, yy)
    days2date(days + n)
    # print('')
