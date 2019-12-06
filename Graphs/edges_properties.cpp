#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define debug(i) cout << i << endl;
#define debugarr(a) for(auto i : a) cout << i << " ";

#define lli long long
#define vi vector<int>
#define vli vector<li>
#define vlli vector<lli>
#define pi pair<int,int>
#define pli pair<li, li>
#define vpi vector<pi>

#define N 1000
#define UNVISITED -1
#define EXPLORED 1
#define VISITED 2

using namespace std;

vi dfs_num(N, UNVISITED);
vi adj[N];

void graph_check(int no, int pai) {
    dfs_num[no] = EXPLORED;
    for(int v : adj[no]) {
        if(dfs_num[v] == UNVISITED) {
            cout << " DFS Tree: " << no << "-" << v << endl;
            graph_check(v, no);
        }
        else if(dfs_num[v] == EXPLORED) {
            if(v == pai)
                cout << " Two ways: " << no << "-" << v << endl;
            else
                cout << " Back-edge: " << no << "-" << v << endl;
        }else if(dfs_num[v] == VISITED) {
            cout << " Forward/Cross edge: " << no << "-" << v << endl;
        }
    }
    dfs_num[no] = VISITED;
}

int main() {
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].PB(b);
        adj[b].PB(a);
    }

    for(int i = 0; i < n; i++)
        if(dfs_num[i] == UNVISITED)
            cout << "Component " << i << endl, graph_check(i, i);
}
