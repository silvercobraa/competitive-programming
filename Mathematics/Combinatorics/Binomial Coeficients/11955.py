T = int(input())
for t in range(T):
    line = input()
    s, exp = line.split('^')
    exp = int(exp)
    a, b = s[1:-1].split('+')
    print('Case %d: ' % (t+1), end='')
    coef = 1
    mul = exp
    div = 1
    print(a, end='')
    if exp >= 2:
        print('^%d' % exp, end='')
    for i in range(exp):
        print('+', end='')
        coef *= mul
        coef //= div
        mul -= 1
        div += 1
        if coef != 1:
            print('%d*' % coef, end='')
        exp1, exp2 = exp-i-1, i+1
        # print(exp1, exp2)
        if exp1 >= 1:
            print(a, end='')
            if exp1 >= 2:
                print('^%d' % exp1, end='')
            print('*', end='')
        if exp2 >= 1:
            print('%s' % b, end='')
            if exp2 >= 2:
                print('^%d' % exp2, end='')
    print('')
