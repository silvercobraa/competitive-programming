import sys

symbol = '0123456789ABCDEF'

value = {
    '0': 0,
    '1': 1,
    '2': 2,
    '3': 3,
    '4': 4,
    '5': 5,
    '6': 6,
    '7': 7,
    '8': 8,
    '9': 9,
    'A': 10,
    'B': 11,
    'C': 12,
    'D': 13,
    'E': 14,
    'F': 15,
}

for line in sys.stdin:
    s, base1, base2 = line.split()
    base1, base2 = int(base1), int(base2)
    number = 0
    for digit in s:
        number *= base1
        number += value[digit]
    ans = ''
    while number != 0:
        digit = number % base2
        ans += symbol[digit]
        number //= base2
    ans = ans[::-1]
    if len(ans) > 7:
        print('  ERROR')
    elif ans == '':
        print('%7d' % 0)
    else:
        print('%7s' % ans)
