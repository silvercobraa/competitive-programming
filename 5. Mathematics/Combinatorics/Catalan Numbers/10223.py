import sys

C = [1]
while C[-1] < 2**32:
    tmp = 0
    for i in range(len(C)):
        tmp += C[i] * C[len(C)-i-1]
    C.append(tmp)

ans = {x: i for i, x in enumerate(C)}
# print(C)
for line in sys.stdin:
    print(ans[int(line)])
