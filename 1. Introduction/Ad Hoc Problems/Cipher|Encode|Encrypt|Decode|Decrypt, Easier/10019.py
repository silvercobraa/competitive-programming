N = int(input())

for _ in range(N):
    M = input()
    b1 = bin(int(M)).count("1")
    b2 = bin(int(M, 16)).count("1")
    print(b1, b2)