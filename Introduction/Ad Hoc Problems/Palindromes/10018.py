n = int(input())

for i in range(n):
    s = input()
    it = 0
    while int(s) != int(s[::-1]):
        s = str(int(s) + int(s[::-1]))
        it += 1
    print(it, s)
