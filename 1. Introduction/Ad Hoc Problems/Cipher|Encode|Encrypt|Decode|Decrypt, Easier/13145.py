import sys
from string import ascii_lowercase, ascii_uppercase

while True:
    N = int(input())
    n = ((N % 26) + 26) % 26
    if N == 0:
        break
    rotated_lowercase = ascii_lowercase[n:] + ascii_lowercase[:n]
    rotated_uppercase = ascii_uppercase[n:] + ascii_uppercase[:n]
    mapping = str.maketrans(ascii_lowercase + ascii_uppercase, rotated_lowercase + rotated_uppercase)
    print(input().translate(mapping))
