import sys
import math

for line in sys.stdin:
    D, V = map(int, line.split())
    if D == 0 and V == 0:
        break
    # Volumen es cilindro grande menos cilindro chico menos 2 conos truncados. despejar d
    d = ((math.pi*D**3 - 6*V) / math.pi)**(1/3)
    print('%.3f' % d)
