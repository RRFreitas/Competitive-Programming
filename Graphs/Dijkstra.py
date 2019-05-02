"""
    Author: Rennan Rocha
"""

from heapq import *

def dijkstra(node):
    q = []
    
    dist[node] = 0
    heappush(q, (0, node))

    while len(q) > 0:
        top = heappop(q)

        for vizinho in adj[top[1]]:
            if dist[vizinho[1]] > dist[top[1]] + vizinho[0]:
                dist[vizinho[1]] = dist[top[1]] + vizinho[0]
                heappush(q, (dist[vizinho[1]], vizinho[1]))


v, a = map(int, input().split())
ini = int(input().split())

adj = [[] for i in range(v)]
dist = [float("inf")] * v

for i in range(a):
    a, b, p = map(int, input().split())

    adj[a].append((p, b))
    adj[b].append((p, a))

m = dijkstra(ini)
print(dist)
