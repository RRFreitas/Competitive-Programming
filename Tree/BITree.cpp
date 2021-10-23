// tree is 1-indexed, base is 0-indexed
struct BIT{
    int size;
    vector<ll> tree;
    vector<ll> base;

    BIT(vector<ll> &base) : base(base) {
        size = base.size();
        tree.resize(size+1);
        for(int i = 1; i <= size; i++)
            update(i, base[i-1]);
    }

    void update(int i, ll val) {
        for(; i <= size; i += (i&-i))
            tree[i] += val;
    }

    ll getSum(int i) {
        ll ans = 0;
        for(; i > 0; i -= (i&-i))
            ans += tree[i];
        return ans;
    }

    ll query(int l, int r) {
        return getSum(r) - getSum(l-1);
    }
};
