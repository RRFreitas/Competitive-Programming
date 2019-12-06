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

using namespace std;

vi dfs_num(N, UNVISITED);
vi dfs_low(N, 0);
vi articulation_point(N, false);

vi adj[N];
int dfsNumberCount = 0;
int dfsRoot, rootChildren;

void artPointAndBridge(int no, int pai) {
    dfs_num[no] = dfs_low[no] = dfsNumberCount++;

    for(int v : adj[no]) {
        if(dfs_num[v] == UNVISITED) {
            if(no == dfsRoot) rootChildren++;

            artPointAndBridge(v, no);
            if(dfs_low[v] >= dfs_num[no]) // articulation point
                articulation_point[no] = true;
            if(dfs_low[v] > dfs_num[no]) // bridge
                cout << " Bridge: " << no << "-" << v << endl;
            dfs_low[no] = min(dfs_low[no], dfs_low[v]);
        }
        else if(v != pai)
            dfs_low[no] = min(dfs_low[no], dfs_num[v]);
    }
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

    cout << "Bridges: " << endl;
    for(int i = 0; i < m; i++)
        if(dfs_num[i] == UNVISITED) {
            dfsRoot = i;
            rootChildren = 0;
            artPointAndBridge(i, i);
            articulation_point[dfsRoot] = (rootChildren > 1);
        }

    cout << "Articulation points: " << endl;
    for(int i = 0; i < n; i++)
        if(articulation_point[i])
            cout << " Vertex: " << i << endl;
}
