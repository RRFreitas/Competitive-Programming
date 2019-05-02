"""
    Author: Rennan Rocha
"""

class UnionFind:
    def __init__(self, N):
        self.par = [i for i in range(N)]
        self.rank = [1 for i in range(N)]
        self.rank[0] = 0

    def union(self, x, y):
        if not self.is_same_set(x, y):
            par_x = self.find_par(x)
            par_y = self.find_par(y)
            if self.rank[par_x] > self.rank[par_y]:
                self.par[par_y] = par_x
                self.rank[par_x] += self.rank[par_y]
                self.rank[par_y] = 0
            else:
                self.par[par_x] = par_y
                self.rank[par_y] += self.rank[par_x]
                self.rank[par_x] = 0

    def find_par(self, x):
        if x == self.par[x]: return x
        self.par[x] = self.find_par(self.par[x])
        return self.par[x]

    def is_same_set(self, x, y):
        return self.find_par(x) == self.find_par(y)
    
    def size(self, x):
        return self.rank[self.find_par(x)]


v, e = map(int, input().split())

uf = UnionFind(v+1)

adj = [[] for i in range(v+1)]

for i in range(e):
    a, b = map(int, input().split())
    uf.union(a, b)
    adj[a].append(b)
    adj[b].append(a)

