import sys

count = 0
for line in sys.stdin:
    left, right = line.strip().split('=')
    if left.find('+') != -1:
        a, b = left.split('+')
        c = str(int(a) + int(b))
    elif left.find('-') != -1:
        a, b = left.split('-')
        c = str(int(a) - int(b))
    if c == right:
        count += 1
print(count)
