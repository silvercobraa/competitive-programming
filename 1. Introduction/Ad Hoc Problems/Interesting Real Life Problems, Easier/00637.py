import sys

for line in sys.stdin:
    n = int(line)
    if n == 0:
        break

    sheets = (n + 3) // 4
    print('Printing order for %d pages:' % n)
    for i in range(sheets):
        a = 4*sheets - (2*i)
        b = 2*i + 1
        c = 2*i + 2
        d = 4*sheets - (2*i + 1)
        if a > n: a = 'Blank'
        if b > n: b = 'Blank'
        if c > n: c = 'Blank'
        if d > n: d = 'Blank'
        if a != 'Blank' or b != 'Blank':
            print('Sheet ' + str(i + 1) + ', front: ' + str(a) + ', ' + str(b));
        if c != 'Blank' or c != 'Blank':
            print('Sheet ' + str(i + 1) + ', back : ' + str(c) + ', ' + str(d));
