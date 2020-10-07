import sys

number = ''
for line in sys.stdin:
    number += line.strip()
    if number.endswith('#'):
        value = int(number[:-1], 2)
        # print(value)
        if value % 131071 == 0:
            print('YES')
        else:
            print('NO')
        number = ''
