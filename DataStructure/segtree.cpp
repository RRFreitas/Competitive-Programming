#define LEFT(x) (x<<1)
#define RIGHT(x) (x<<1|1)
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
template<class node, class T>
struct SegTree {
    int size;
    vector<node> tree;
    vector<T> base;

    SegTree(vector<T> base) : base(base) {
        size = base.size();
        tree.resize(4 * size);
        build(1, 1, size);
    }

    void build(int i, int l, int r) {
        if(l == r)
            tree[i] = node(base[l-1]);
        else {
            int mid = (l+r)>>1;
            build(LEFT(i), l, mid);
            build(RIGHT(i), mid+1, r);
            tree[i] = node(tree[LEFT(i)], tree[RIGHT(i)]);
        }
    }

    node qry(int i, int l, int r, int x, int y) {
        if(l >= x && r <= y) return tree[i];
        else if(r < x || l > y) return node();
        else {
            int mid = (l+r)>>1;
            return nodee(qry(LEFT(i), l, mid, x, y), qry(RIGHT(i), mid+1, r, x, y));
        }
    }

    node query(int l, int r) {
        return qry(1, 1, size, l, r);
    }

    void upd(int i, int l, int r, int x, T val) {
        if(l == r) tree[i] = node(val); //alterar para merge ou set
        else {
            int mid = (l+r)>>1;
            if(x <= mid) upd(LEFT(i), l, mid, x, val);
            else upd(RIGHT(i), mid+1, r, x, val);
            tree[i] = node(tree[LEFT(i)], tree[RIGHT(i)]);
        }
    }

    void update(int x, T val) {
        upd(1, 1, size, x, val);
    }
};

int main() {
    SegTree<Node, int> tree = SegTree<Node, int>(arr);
}
