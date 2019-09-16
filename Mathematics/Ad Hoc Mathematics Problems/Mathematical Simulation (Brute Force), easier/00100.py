import sys
# import time

MAX = 1000000
cycle_length = [None for i in range(MAX)]
# ti = time.perf_counter()
for i in range(MAX):
    length = i + 1
    count = 1
    while length != 1:
        if length % 2 == 0:
            length = length // 2
        else:
            length = 3*length + 1
        if length < MAX and cycle_length[length-1] is not None:
            count += cycle_length[length-1]
            break
        count += 1

    cycle_length[i] = count
# tf = time.perf_counter()
# print(tf - ti)


for line in sys.stdin:
    i, j = map(int, line.split())
    best = 0
    if i < j:
        for k in range(i-1, j):
            best = max(best, cycle_length[k])
        print(i, j, best)
    else:
        for k in range(j-1, i):
            best = max(best, cycle_length[k])
        print(i, j, best)
