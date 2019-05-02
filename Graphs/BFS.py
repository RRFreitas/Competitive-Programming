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

def bfs(node):
    fila = [node]

    while len(fila) > 0:
        top = fila.pop(0) # recomendável substituir por uma queue pois lista.pop(0) faz O(N) operações
        vis[top] = True

        print("Entrando no", top)
        for parent in adj[top]:
            if not vis[parent]:
                fila.append(parent)
        print("Saindo do", top)

bfs(ini)
