from math import sin, cos, pi, atan
import sys

for line in sys.stdin:
    l, w, h, th = map(int, line.split())
    th = pi*th/180
    max_th = atan(h/l)
    if th <= max_th:
        y = (l/cos(th)) * sin(th)
        vol = l*w*y / 2
        print('%.3f mL' % (l*w*h - vol))
    else:
        x = (h/cos(pi/2 - th)) * sin(pi/2 - th)
        vol = h*w*x / 2
        print('%.3f mL' % vol)
