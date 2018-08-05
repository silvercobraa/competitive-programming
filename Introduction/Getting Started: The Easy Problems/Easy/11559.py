#!/usr/bin/env python
# coding=utf-8
# César Bolívar Severino
# resuelto propio

# def find_hotel(N, B, H, W, s):
#     res = 'stay home'
#     for i in range(H):
#         p = int(input())
#         b = input().split()
#         # b = map(int, input().split())
#         for j in b:
#             if int(j) < N:
#                 res = 'stay home'
#                 break
#
#         if N*p*W <= B:
#             if res != 'stay home' and res > N*p*W:
#             res = N*p*W
#
#     return res

def test_hotel(N, b):
    for j in b:
        if int(j) >= N:
            return True
    return False

try:
    l = input()
    while l != '':
        s = l.split()

        N = int(s[0]) # numero personas
        B = int(s[1]) # 'budget'
        H = int(s[2]) # hoteles
        W = int(s[3]) # 'weekends'

        res = 'stay home'
        for i in range(H):
            p = int(input())
            b = input().split()
            # print(f'p: {p}, b: {b}')
            # b = map(int, input().split())

            cost = N*p
            if cost <= B and test_hotel(N, b):
                if res == 'stay home':
                    res = cost
                else:
                    res = min(res, cost)
                # if res != 'stay home' and res > N*p*W:
                #     res = N*p*W

        print(res)
        l = input()
        s = l.split()
except EOFError as eofe:
    pass
