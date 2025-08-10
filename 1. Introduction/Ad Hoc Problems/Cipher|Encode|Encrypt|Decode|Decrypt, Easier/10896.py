g = ord("a")  # gorda
n = int(input())


def shift(c):
    if c.isalpha():
        return chr((ord(c) - g - i + 26) % 26 + g)
    else:
        return c


for _ in range(n):
    sentence = input()
    word = input()
    for i in range(26):
        shifted = "".join([shift(c) for c in sentence]).split()
        if word in shifted:
            print(chr(g + i), end="")
    print("")
