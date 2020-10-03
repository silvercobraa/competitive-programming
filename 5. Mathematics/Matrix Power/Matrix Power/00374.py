import math
import sys

B = None
P = None
M = None
for line in sys.stdin:
    if B == None:
        B = int(line)
    elif P == None:
        P = int(line)
    elif M == None:
        M = int(line)
    else:
        print(pow(B, P, M))
        B, P, M = None, None, None

if M != None:
    print(pow(B, P, M))
    B, P, M = None, None, None
