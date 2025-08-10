import sys

valid = [c for c in range(65, 90+1)] + [c for c in range(97, 122+1)] + [32, 33, 44, 46, 58, 59, 63]
valid = {str(c) for c in valid}
# print(valid)

for line in sys.stdin:
    s = line.rstrip("\n")
    if s.isnumeric():
        s = s[::-1]
        i = 0
        while i < len(s):
            if i+3 <= len(s) and s[i:i+3] in valid:
                print(chr(int(s[i:i+3])), end="")
                i += 3
            elif i+2 <= len(s) and s[i:i+2] in valid:
                print(chr(int(s[i:i+2])), end="")
                i += 2
            else:
                print("WTF")
        print("")
    else:
        print("".join(str(ord(c))[::-1] for c in s[::-1]))
    # print([int(str(ord(c))[::-1]) for c in line])