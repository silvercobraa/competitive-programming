import sys
from collections import Counter

first = True
plain = ""
cipher = ""
for line in sys.stdin:
    if first:
        cipher = line.rstrip("\n")
    else:
        plain = line.rstrip("\n")
        plain = [c for c in plain if c.isalpha() and c.upper() == c]
        plain_count = Counter(plain)
        cipher_count = Counter(cipher)
        if sorted(plain_count.values()) == sorted(cipher_count.values()):
            print("YES")
        else:
            print("NO")
    first = not first