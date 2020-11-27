
class DSU:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.size = [1 for i in range(n)]

    def find(self, x):
        if self.parent[x] == x:
            return x
        else:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        a, b = self.find(x), self.find(y)
        if self.size[a] > self.size[b]:
            self.parent[b] = a
            self.size[a] += self.size[b]
        else:
            self.parent[a] = b
            self.size[b] += self.size[a]


T = int(input())
for t in range(T):
    N = int(input())
    id_ = {}
    pairs = []
    for i in range(N):
        s1, s2 = input().split()
        if s1 not in id_:
            id_[s1] = len(id_)
        if s2 not in id_:
            id_[s2] = len(id_)
        pairs.append((s1, s2))
    dsu = DSU(len(id_))
    for s1, s2 in pairs:
        x, y = dsu.find(id_[s1]), dsu.find(id_[s2])
        if x != y:
            dsu.union(x, y)
        print(dsu.size[dsu.find(x)])
        # print(dsu.size)
