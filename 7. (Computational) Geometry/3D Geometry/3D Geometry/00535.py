from math import sin, cos, pi, acos, sqrt

r = 6378
def spheric2cartesian(theta, phi):
    return (r*cos(theta)*cos(phi), r*sin(theta)*cos(phi), r*sin(phi))

def norm(u):
    return sqrt(sum(ui**2 for ui in u))

def dot(u, v):
    return sum(ui*vi for ui, vi in zip(u, v))

line = input().strip()
angles = {}
while line != '#':
    city, lat, long = line.split()
    lat = float(lat) * pi / 180
    long = float(long) * pi / 180
    # print(lat, long)
    angles[city] = (long, lat)
    line = input().strip()


line = input().strip()
while line != '# #':
    city1, city2 = line.split()
    print(city1, '-', city2)
    if city1 not in angles or city2 not in angles:
        print('Unknown')
        line = input().strip()
        continue
    # print(angles[city1], angles[city2])
    u = spheric2cartesian(*angles[city1])
    v = spheric2cartesian(*angles[city2])
    # print(u, v)
    tmp = dot(u, v) / (norm(u) * norm(v))
    if tmp > 1:
        tmp = 1
    if tmp < -1:
        tmp = -1
    # print(tmp)
    angle = acos(tmp)
    arc = angle*r
    # print(angle)
    print(int(round(arc, 0)), 'km')
    line = input().strip()
