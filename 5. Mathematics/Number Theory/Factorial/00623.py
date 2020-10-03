import sys

l = [1]
while len(l) <= 1000:
    l.append(l[-1]*len(l))

for line in sys.stdin:
    n = int(line)
    print(str(n) + '!')
    print(l[n])
