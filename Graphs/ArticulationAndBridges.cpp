#define N 1000
#define UNVISITED -1

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
