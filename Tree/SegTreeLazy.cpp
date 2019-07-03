#include <bits/stdc++.h>

#define ll long long

#define N 1000000
#define LEFT(x) (x<<1)
#define RIGHT(x) ((x<<1)|1)

using namespace std;

ll tree[4 * N];
ll lazy[4 * N];

void doLazy(int i, int l, int r) {
    if(lazy[i]) {
        tree[i] += (r-l+1) * lazy[i];
        if(l != r) {
            lazy[LEFT(i)] += lazy[i];
            lazy[RIGHT(i)] += lazy[i];
        }
        lazy[i] = 0;
    }
}

void update(int i, int l, int r, int x, int y, int v) {
    doLazy(i, l, r);
    if(l > y || r < x) return;
    else if(l >= x && r <= y) {
        lazy[i] += v;
        doLazy(i, l, r);
    }else {
        int mid = (l+r) >> 1;
        update(LEFT(i), l, mid, x, y, v);
        update(RIGHT(i), mid + 1, r, x, y, v);
        tree[i] = tree[LEFT(i)] + tree[RIGHT(i)];
    }
}

ll query(int i, int l, int r, int x, int y) {
    doLazy(i, l, r);
    if(l > y || r < x) return 0;
    else if(l >= x && r <= y) return tree[i];
    else {
        int mid = (l+r) >> 1;
        return query(LEFT(i), l, mid, x, y) + query(RIGHT(i), mid + 1, r, x, y);
    }
}

int main() {
    // 0 0 0 0 0 0 0 0
    update(1, 1, N, 2, 4, 26); // 0 26 26 26 0 0 0 0
    update(1, 1, N, 4, 8, 80); // 0 26 26 106 80 80 80 80
    cout << query(1, 1, N, 8, 8) << endl; // 80
    update(1, 1, N, 4, 5, 20); // 0 26 26 126 100 80 80 80
    update(1, 1, N, 5, 7, 14); // 0 26 26 126 114 94 94 80
    cout << query(1, 1, N, 4, 8) << endl; // 508
}
