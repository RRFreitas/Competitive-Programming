#define LEFT(x) (x<<1)
#define RIGHT(x) ((x<<1)|1)

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

// 1-indexed
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
