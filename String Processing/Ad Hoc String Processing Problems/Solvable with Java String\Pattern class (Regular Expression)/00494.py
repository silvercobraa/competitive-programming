import sys

for line in sys.stdin:
    words = 0
    prev = ' '
    for c in line:
        if c.isalpha() and not prev.isalpha():
            words += 1
        prev = c
    print(words)
