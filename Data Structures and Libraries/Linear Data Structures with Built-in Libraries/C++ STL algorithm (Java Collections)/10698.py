line = input().strip()

firstinput = True
while line != '0 0':
    if not firstinput:
        print('')
    else:
        firstinput = False
    T, G = map(int, line.split())
    # print(T, G)
    teams = [input().strip() for _ in range(T)]
    points = {team: 0 for team in teams}
    played = {team: 0 for team in teams}
    scored = {team: 0 for team in teams}
    suffered = {team: 0 for team in teams}
    goaldiff = {team: 0 for team in teams}
    for _ in range(G):
        t1, g1, _, g2, t2 = input().strip().split()
        g1, g2 = int(g1), int(g2)
        # print(t1, g1, g2, t2)
        points[t1] += 3 if g1 > g2 else 1 if g1 == g2 else 0
        points[t2] += 3 if g2 > g1 else 1 if g1 == g2 else 0
        played[t1] += 1
        played[t2] += 1
        scored[t1] += g1
        scored[t2] += g2
        suffered[t1] += g2
        suffered[t2] += g1
        goaldiff[t1] += g1 - g2
        goaldiff[t2] += g2 - g1
    # primero ordeno alfabeticamente, luego el siguiente sort como es estable preserva el orden de este criterio
    teams.sort(key=lambda t: t.lower())
    teams.sort(key=lambda t: (points[t], goaldiff[t], scored[t]), reverse=True)
    prev = (-1, -1, -1)
    for i, t in enumerate(teams):
        stats = (points[t], goaldiff[t], scored[t])
        if stats == prev:
            print('   ', end='')
        else:
            print('%2d.' % (i+1), end='')
        ans = (t, points[t], played[t], scored[t], suffered[t], goaldiff[t])
        print('%16s%4d%4d%4d%4d%4d' % ans, end='')
        if played[t] > 0:
            print('%7.2f' % (100*points[t] / (3*played[t])))
        else:
            print('    N/A')
        prev = stats

    line = input().strip()
