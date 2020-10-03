#!/usr/bin/env python
# coding=utf-8
# César Bolívar Severino
# resuelto propio

def snail(H, U, D, F):
    p = 0.0
    Ui = float(U)
    n = 1
    while True:
        p += Ui
        if p > H:
            print('success on day', n)
            return
        p -= D
        if p < 0:
            print('failure on day', n)
            return
        Ui -= U*F/100 # caracol re ctm
        if Ui < 0:
            Ui = 0
        n += 1


l = input().split()

while int(l[0]) != 0:
    H = int(l[0])
    U = int(l[1])
    D = int(l[2])
    F = int(l[3])

    snail(H, U, D, F)
    l = input().split()
