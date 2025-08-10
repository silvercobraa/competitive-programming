import sys

int2str = "_abcdefghijklmnopqrstuvwxyz."
str2int = {char: index for index, char in enumerate(int2str)}

for line in sys.stdin:
    s = line.rstrip("\n")
    if s == "0":
        break
    key, cipher = s.split(" ")
    key = int(key)
    n = len(cipher)
    mapping = [key * i % n for i in range(n)]
    inverse_mapping = {char: index for index, char in enumerate(mapping)}
    print("".join(int2str[(str2int[cipher[inverse_mapping[i]]] + inverse_mapping[i]) % 28] for i in range(n)))