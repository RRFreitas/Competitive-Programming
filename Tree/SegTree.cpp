#include <bits/stdc++.h>

#define ll long long

#define LEFT(x) (x<<1)
#define RIGHT(x) (x<<1|1)

using namespace std;

struct Node {
    // attributes


    Node() {
        // neutral constructor

    }

    Node() {
        // init

    }

    Node(Node l, Node r) {
        // merge

    }
};


template<class i_t, class e_t>
struct SegTree {
    int size;
    vector<i_t> tree;
    vector<e_t> base;

    SegTree(vector<e_t> base) : base(base) {
        size = base.size();
        tree.resize(4 * size);
        build(1, 1, size);
    }

    void build(int i, int l, int r) {
        if(l == r)
            tree[i] = i_t(base[l-1]);
        else {
            int mid = (l+r)>>1;
            build(LEFT(i), l, mid);
            build(RIGHT(i), mid+1, r);
            tree[i] = i_t(tree[LEFT(i)], tree[RIGHT(i)]);
        }
    }

    i_t qry(int i, int l, int r, int x, int y) {
        if(l >= x && r <= y) return tree[i];
        else if(r < x || l > y) return i_t();
        else {
            int mid = (l+r)>>1;
            return i_t(qry(LEFT(i), l, mid, x, y), qry(RIGHT(i), mid+1, r, x, y));
        }
    }

    i_t query(int l, int r) {
        return qry(1, 1, size, l, r);
    }

    void upd(int i, int l, int r, int x, e_t val) {
        if(l == r) tree[i] = i_t(val); //alterar para merge ou set
        else {
            int mid = (l+r)>>1;
            if(x <= mid) upd(LEFT(i), l, mid, x, val);
            else upd(RIGHT(i), mid+1, r, x, val);
            tree[i] = i_t(tree[LEFT(i)], tree[RIGHT(i)]);
        }
    }

    void update(int x, e_t val) {
        upd(1, 1, size, x, val);
    }
};

int main() {
    SegTree<Node, int> tree = SegTree<Node, int>(arr);
}
