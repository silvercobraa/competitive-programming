n, m = map(int, input().split())
irregular = {}
vowels = {'a', 'e', 'i', 'o', 'u'}
for i in range(n):
    a, b = input().split()
    irregular[a] = b

for j in range(m):
    word = input().strip()
    if word in irregular:
        print(irregular[word])
    elif len(word) >= 2 and word[-2] not in vowels and word.endswith('y'):
        print(word[:-1] + 'ies')
    elif word.endswith('o') or word.endswith('s') or word.endswith('ch') or word.endswith('sh') or word.endswith('x'):
        print(word + 'es')
    else:
        print(word + 's')
