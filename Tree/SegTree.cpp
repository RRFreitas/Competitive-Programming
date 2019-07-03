#include <bits/stdc++.h>

#define ll long long

#define esq(x) 2*(x)
#define dir(x) (2*(x))+1

#define MAX 1000000

using namespace std;

ll segTree[4 * MAX];
ll arr[MAX];

ll build(int ind, int l, int r) {
    if(l == r) return segTree[ind] = arr[l-1];
    int mid = (l + r) >> 1;
    return segTree[ind] = build(esq(ind), l, mid) +
            build(dir(ind), mid + 1, r);
}

ll query(int ind, int l, int r, int A, int B) {
    if(l >= A && r <= B) return segTree[ind];
    if(r < A || l > B) return 0;
    int mid = (l + r) >> 1;
    return query(esq(ind), l, mid, A, B) +
            query(dir(ind), mid+1, r, A, B);
}

ll update(int ind, int l, int r, int x, int val) {
    if(l == r) return segTree[ind] += val;
    int mid = (l + r) >> 1;
    if(x <= mid) update(esq(ind), l, mid, x, val);
    else update(dir(ind), mid+1, r, x, val);
    return segTree[ind] = segTree[esq(ind)] + segTree[dir(ind)];
}

int main() {
}
