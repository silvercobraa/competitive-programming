import sys

def mul(M1, M2, m):
    return [
        [
            (M1[0][0]*M2[0][0] + M1[0][1]*M2[1][0]) % m,
            (M1[0][0]*M2[0][1] + M1[0][1]*M2[1][1]) % m,
        ],
        [
            (M1[1][0]*M2[0][0] + M1[1][1]*M2[1][0]) % m,
            (M1[1][0]*M2[0][1] + M1[1][1]*M2[1][1]) % m,
        ],
    ]

def pow(M, e, m):
    # ans = M
    ans = [[1, 0], [0, 1]]
    while e != 0:
        if e % 2 == 1:
            ans = mul(M, ans, m)
        M = mul(M, M, m)
        e //= 2
    return ans

for x, line in enumerate(sys.stdin):
    n, m = map(int, line.split())
    if m == 0:
        print(0)
        continue
    if n == 0:
        # fib(0) = 1, por lo tanto modulo cualquier cosa es cero
        print(0)
        continue
    elif n == 1:
        # if m == 0:
        print(1)
        continue
    M = [[1, 1], [1, 0]]
    ans = pow(M, n-1, 2**m)
    # print(2**m)
    print(ans[0][0])
