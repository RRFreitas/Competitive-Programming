struct DSU {
    vi pai, rankk;

    DSU(int n) {
        pai.assign(n+1, 0);
        rankk.assign(n+1, 1);
        for(int i = 0; i <= n; i++)
            pai[i] = i;
    }

    int find(int x) {
        if(pai[x] == x) return x;
        return pai[x] = find(pai[x]);
    }

    bool same_set(int a, int b) {
        return find(a) == find(b);
    }

    void join(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if(pa == pb) return;

        if(pa == pb) return;
        if(rankk[pa] >= rankk[pb]) {
            pai[pb] = pa;
            rankk[pa] += rankk[pb];
        } else {
            pai[pa] = pb;
            rankk[pb] += rankk[pa];
        }

        find(a); find(b);
    }
};
