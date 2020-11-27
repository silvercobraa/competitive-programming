#!/usr/bin/env python
# coding=utf-8
# César Bolívar Severino
# resuelto propio

# 'Tabla' de transcisión
T = {
    '+x': {'+y':'+y', '-y':'-y', '+z':'+z', '-z':'-z', 'No':'+x'},
    '-x': {'+y':'-y', '-y':'+y', '+z':'-z', '-z':'+z', 'No':'-x'},
    '+y': {'+y':'-x', '-y':'+x', '+z':'+y', '-z':'+y', 'No':'+y'},
    '-y': {'+y':'+x', '-y':'-x', '+z':'-y', '-z':'-y', 'No':'-y'},
    '+z': {'+y':'+z', '-y':'+z', '+z':'-x', '-z':'+x', 'No':'+z'},
    '-z': {'+y':'-z', '-y':'-z', '+z':'+x', '-z':'-x', 'No':'-z'}
}

l = input()

while l != '0':
    # L = int(l)
    D = input().split() # desiciones
    d = '+x' # dirección en la que apunta el ultimo segmento

    for i in D:
        d = T[d][i]
        # print(d)

    print(d)
    l = input()
