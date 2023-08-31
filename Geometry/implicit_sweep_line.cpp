struct node {
    pair<ll,ll> val;
    ll lazy;
    node *esq, *dir;
    node(ll l, ll r) {
        val = {0,r-l+1};
        lazy = 0;
        esq = dir = NULL;
    }
};

pair<ll,ll> merge(pair<ll,ll> q1, pair<ll,ll> q2) {
    if(q1.F == q2.F) return MP(q1.F, q1.S + q2.S);
    else return min(q1, q2);
}

void doLazy(node &no) {
    if(no.lazy != 0) {
        no.val.F += no.lazy;
        if(no.esq != NULL)
            no.esq->lazy += no.lazy;
        if(no.dir != NULL)
            no.dir->lazy += no.lazy;
        no.lazy = 0;
    }
}
 
void update(node &no, ll l, ll r, ll x, ll y, ll val) {
    doLazy(no);
    if(l >= x && r <= y) {
        no.lazy += val;
        doLazy(no);
    }else if(r < x || l > y) return;
    else {
        ll mid = (l+r)>>1;    
        if(no.esq == NULL)
            no.esq = new node(l, mid);
        update(*no.esq, l, mid, x, y, val);
        if(no.dir == NULL)
            no.dir = new node(mid+1, r);
        update(*no.dir, mid+1, r, x, y, val);
        no.val = merge(no.esq->val, no.dir->val);
    }
}
 
pair<ll,ll> query(node &no, ll l, ll r, ll x, ll y) {
    doLazy(no);
    if(l >= x && r <= y) {
        return no.val;
    } else if(r < x || l > y) return MP(INF,0);
    else {
        ll mid = (l+r)>>1;
        if(no.esq == NULL)
            no.esq = new node(l, mid);
        if(no.dir == NULL)
            no.dir = new node(mid+1, r);
        return merge(query(*no.esq, l, mid, x, y), query(*no.dir, mid+1, r, x, y));
    }
}
