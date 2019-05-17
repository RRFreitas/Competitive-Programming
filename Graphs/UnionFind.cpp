/*
 *  Author: Rennan Rocha
 */

#include <bits/stdc++.h>
#define MAX 100
#define INF 100000

using namespace std;

class UnionFind {
    private:
        int *p, *rank, n;
    public:
        UnionFind(int Size): n(Size) {
            p = new int[n+1];
            rank = new int[n+1];
            for(int i = 0; i <= n; i++) {
                p[i] = i;
                rank[i] = 1;
            }
        }
        ~UnionFind() {delete []p;}
        void Union(int i, int j);
        int Find(int i);
        bool Same_Set(int i, int j);
        int Size(int i);
};

void UnionFind::Union(int i, int j) {
   if (!Same_Set(i, j)) {
        int par_i = Find(i);
        int par_j = Find(j);
        if (rank[par_i] > rank[par_j]) {
            p[par_j] = par_i;
            rank[par_i] += rank[par_j];
            rank[par_j] = 0;
        }else {
            p[par_i] = par_j;
            rank[par_j] += rank[par_i];
            rank[par_i] = 0;
        }
   }
}

int UnionFind::Find(int i) {
    if (p[i] == i) return i;
    return p[i] = Find(p[i]);
}

bool UnionFind::Same_Set(int i, int j) { return Find(i) == Find(j); }

int UnionFind::Size(int i) { return rank[Find(i)]; }   

int main() {
    UnionFind uf = (MAX);
    
    uf.Union(1, 2);
    uf.Union(3, 4);
    uf.Union(5, 6);
    uf.Union(7, 8);
    uf.Union(1, 3);
    uf.Union(5, 7);
    uf.Union(1, 5);

    for(int i = 1; i <= 8; i++)
        cout << i << " " << uf.Find(i) << endl;
    cout << endl;
    for(int i = 1; i <= 8; i++)
        cout << i << " " << uf.Size(i) << endl;
}
