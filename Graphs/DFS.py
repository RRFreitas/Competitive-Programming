"""
    Author: Rennan Rocha
"""

v, a, ini = map(int, input().split())

adj = [[] for i in range(v + 1)]

vis = [False for i in range(v + 1)]

for i in range(a):
    a, b = map(int, input().split())

    adj[a].append(b)
    adj[b].append(a)

def dfs(node):
    print("Entrando em", node)
    vis[node] = True
    for child in adj[node]:
        if not vis[child]:
            dfs(child)

    print("Voltando para", node)

dfs(ini)
