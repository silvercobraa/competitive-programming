n = int(input())
for i in range(n):
    line = input()
    left = (0, 1)
    middle = (1, 1)
    right = (1, 0)
    for char in line:
        if char == 'L':
            right = middle
        elif char == 'R':
            left = middle
        middle = (left[0] + right[0], left[1] + right[1])
    print(middle[0], '/', middle[1], sep='')
