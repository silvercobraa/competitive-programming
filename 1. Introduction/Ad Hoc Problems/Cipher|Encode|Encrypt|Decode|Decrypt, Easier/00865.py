import sys

T = int(input())
s = input()

cases = sys.stdin.read().split("\n\n")

for i, case_ in enumerate(cases):
    if i != 0:
        print("")
    lines = case_.split("\n")
    plain = lines[0]
    subst = lines[1]
    tr = str.maketrans(plain, subst)
    # print(tr)
    print(subst)
    print(plain)
    for j in range(2, len(lines)):
        if i + 1 == len(cases) and j + 1 == len(lines):
            print(lines[j].translate(tr), end="")
        else:
            print(lines[j].translate(tr))