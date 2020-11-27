import sys
import re

for line in sys.stdin:
    n = line.strip()
    if n == '*': break
    sign = '[-+]?'
    integer = '[0-9]+'
    fractional = '(\\.[0-9]+)?'
    exponent = '([eE]'+sign+'[1-9][0-9]*)?'
    exponent = '([eE]'+sign+'[0-9]+)?'
    p = sign + integer + fractional + exponent
    # print(p)
    pattern = re.compile(p)
    result = pattern.match(n)
    if result and result.end() == len(n):
    # if result:
        # Si no encuentro ni punto ni exponente, el match es solo parte entera. imprimir "Illegal"
        if n.find('e') == -1 and n.find('E') == -1 and n.find('.') == -1:
            print(n, 'is illegal.')
        else:
            print(n, 'is legal.')
    else:
        print(n, 'is illegal.')
