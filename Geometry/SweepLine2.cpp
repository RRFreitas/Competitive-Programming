#define LEFT(x) (x<<1)
#define RIGHT(x) (x<<1|1)
#define MAXN 1000010
#define INF 1e9+10

using namespace std;

pair<ll,ll> tree[4 * MAXN];
ll lazy[4 * MAXN];

void doLazy(int i, int l, int r) {
    if(lazy[i] != 0) {
        tree[i].F += lazy[i];
        if(l != r) {
            lazy[LEFT(i)] += lazy[i];
            lazy[RIGHT(i)] += lazy[i];
        }
        lazy[i] = 0;
    }
}

pair<ll,ll> merge(pair<ll,ll> q1, pair<ll,ll> q2) {
    if(q1.F == q2.F) return MP(q1.F, q1.S + q2.S);
    else return min(q1, q2);
}

void update(int i, int l, int r, int x, int y, ll v)  {
    doLazy(i, l, r);
    if(l >= x && r <= y) {
        lazy[i] += v;
        doLazy(i, l, r);
    }else if(r < x || l > y) return;
    else {
        int mid = (l+r)>>1;
        update(LEFT(i), l, mid, x, y, v);
        update(RIGHT(i), mid+1, r, x, y, v);
        tree[i] = merge(tree[LEFT(i)], tree[RIGHT(i)]);
    }
}

pair<ll,ll> query(int i, int l, int r, int x, int y) {
    doLazy(i, l, r);
    if(l >= x && r <= y) return tree[i];
    else if(r < x || l > y) return MP(INF, 0);
    else {
        int mid = (l+r)>>1;
        return merge(query(LEFT(i), l, mid, x, y), query(RIGHT(i), mid+1, r, x, y));
    }
}

void build(int i, int l, int r) {
    if(l == r) tree[i] = MP(0,1);
    else{
        int mid = (l+r)>>1;
        build(LEFT(i), l, mid);
        build(RIGHT(i), mid+1, r);
        tree[i] = merge(tree[LEFT(i)], tree[RIGHT(i)]);
    }
}

struct event {
    int x, y1, y2, flag;
    bool operator<(const event &e) const {
        return x < e.x;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    build(1, 1, 1e6);

    int n;
    cin >> n;

    vector<event> events;
    for(int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        event in = {x1, y1, y2, 1}; // flag 1 = entrada; 0 = saida;
        event out = {x2, y1, y2, 0};
        events.PB(in);
        events.PB(out);
    }

    sort(events.begin(), events.end());
    ll ans = 0;
    for(int i = 0; i < events.size(); i++) {
        event ev = events[i];
        
        if(i > 0) {
            pair<ll,ll> q = query(1, 1, 1e6, 1, 1e6); // {menor, quantidade}
            ll total_preenchido = 1e6;
            if(q.F == 0) {
                total_preenchido = 1e6 - q.S; // retirar não preenchidos
            }
            ans += ((ev.x - events[i-1].x) * total_preenchido);
        }
        if(ev.flag == 1) { //in
            update(1, 1, 1e6, ev.y1+1, ev.y2, 1);
        }else { //out
            update(1, 1, 1e6, ev.y1+1, ev.y2, -1);
        }
    }
    cout << ans << endl;
}
