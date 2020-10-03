n = int(input())

for i in range(n):
    s = input()
    v = [0]
    k = 0
    for c in s:
        if c == 'R':
            k += 1
        elif c == 'F':
            k -= 1
        v.append(k)
    min_ = min(v)
    height = max(v) - min_
    graph = [[' ' for j in range(len(s))] for i in range(height+1)]
    row, col = height-(v[0] - min_), 0
    for c in s:
        if c == 'R':
            graph[row][col] = '/'
            row -= 1
        elif c == 'F':
            row += 1
            graph[row][col] = '\\'
        elif c == 'C':
            graph[row][col] = '_'
        col += 1

    print('Case #'+str(i+1)+':')
    for line in graph:
        row = ('| ' + ''.join(line)).strip()
        if row != '|':
            print(row)

    print('+' + (len(s)+2)*'-')
    print('')
