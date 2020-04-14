N = int(input())

for _ in range(N):
    s = input()
    perm = int(input())
    factorial = [1 for _ in s]
    for i in range(1, len(factorial)):
        factorial[i] = i*factorial[i - 1]
    # print(factorial)
    # print(perm)
    s = sorted(s)
    while len(s) > 0:
        count = 0
        while perm >= factorial[-1]:
            perm -= factorial[-1]
            count += 1
        # print(count)
        print(s[count], end='')
        s.pop(count)
        factorial.pop()
    print('')
