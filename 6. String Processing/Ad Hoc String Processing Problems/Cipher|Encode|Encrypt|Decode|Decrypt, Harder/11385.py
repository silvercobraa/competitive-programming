fib_id = {1: 1}
fib = [1]
prev, f = 1, 1
MAX = 2**31
while f <= MAX:
    prev, f = f, prev + f
    fib.append(f)
    fib_id[f] = len(fib)

# print(fib)
# print(fib_id)

T = int(input())
for i in range(T):
    n = int(input())
    fibs = input().split()
    l = max((fib_id[int(f)] for f in fibs))
    # print(l)
    text = [c for c in input() if 'A' <= c <= 'Z']
    # print(text)
    output = [' ' for i in range(l)]
    for j, f in enumerate(fibs):
        # print(j, f, fib_id[int(f)])
        output[fib_id[int(f)]-1] = text[j]
    for c in output:
        print(c, end='')
    print('')
