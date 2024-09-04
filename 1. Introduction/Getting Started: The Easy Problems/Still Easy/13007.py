import sys

cards = [10000, 1000, 100, 10, 1]
line = sys.stdin.readline()
while line:
    N, M = map(int, line.split())
    extra_points = 0
    for _ in range(M):
        B, D, *C = map(int, input().split())
        points = sum(C)
        max_score = 0
        for card in cards:
            if card + points <= B:
                max_score = max(max_score, card)
        if D + points > B:
            extra_points += max_score
        else:
            extra_points += max_score - D
    print(extra_points)
    line = sys.stdin.readline()