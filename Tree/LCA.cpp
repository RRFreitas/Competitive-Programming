const int MAXLOG = 20;

vi adj[1000010];
int pai[1000010][MAXLOG+1];
int nivel[1000010];

struct LCA {
    int raiz;

    LCA(int raiz) : raiz(raiz) {
        nivel[raiz] = -1;
        build(raiz, raiz);
    }

    void build(int no, int p) {
        pai[no][0] = p;
        nivel[no] = nivel[p] + 1;
        for(int i = 1; i <= MAXLOG; i++) {
            pai[no][i] = pai[pai[no][i-1]][i-1];
        }
        for(int v : adj[no])
            if(v != p)
                build(v, no);
    }

    int getLCA(int u, int v) {
        if(nivel[v] > nivel[u])
            swap(u, v);
        if(nivel[u] > nivel[v]) {
            for(int i = MAXLOG; i >= 0; i--) {
                if(nivel[pai[u][i]] > nivel[v])
                    u = pai[u][i];
            }
            u = pai[u][0];
        }
        if(u == v)
            return u;
        for(int i = MAXLOG; i >= 0; i--) {
            if(pai[u][i] != pai[v][i]) {
                u = pai[u][i];
                v = pai[v][i];
            }
        }
        return pai[u][0];
    }

    int query(int u, int v) {
        int lca = getLCA(u, v);
        return nivel[u] + nivel[v] - 2 * nivel[lca];
    }
};
