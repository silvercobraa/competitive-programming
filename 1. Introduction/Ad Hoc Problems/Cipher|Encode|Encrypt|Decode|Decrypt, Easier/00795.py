import sys

lookup = [
    27,  0, 18,  1, 28,  2,
    19, 29,  9, 30,  3, 10,
    31, 20,  4, 11, 21, 32,
    12,  5, 33, 22,  6, 13,
    34, 23, 14, 35, 15,  7,
    24, 16, 25,  8, 26, 17,
]

inv_lookup = {value: index for index, value in enumerate(lookup)}

for line in sys.stdin:
    s = line.rstrip("\n")
    output = ""
    for offset in range(0, len(s), 36):
        block = s[offset: offset+36]
        output += "".join(block[inv_lookup[i]] for i in range(36))
    print(output[::-1].rstrip("#"))
