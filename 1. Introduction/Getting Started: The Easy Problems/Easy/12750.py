import sys

def ans(l):
    count = 3
    for i, x in enumerate(l):
        if x == "W":
            count = 3
        else:
            count -= 1
        if count == 0:
            return i + 1
    return "Yay! Mighty Rafa persists!"


T = sys.stdin.readline()
while T:
    for t in range(int(T)):
        n = int(input())
        print("Case " + str(t+1) + ": ", end="")
        l = [input().strip() for _ in range(n)]
        print(ans(l))
    T = sys.stdin.readline()