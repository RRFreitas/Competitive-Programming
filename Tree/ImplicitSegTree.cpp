#include <bits/stdc++.h>
 
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
 
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define vpi vector<pi>
 
#define MAXN 5000000000000
 
using namespace std;
 
struct node {
    ll val;
    node *esq, *dir;
    node() {
        val = 0;
        esq = dir = NULL;
    }
};
 
void update(node &no, ll l, ll r, ll val) {
    if(l == r) {
        no.val++;
    }else {
        ll mid = (l+r)>>1;    
        if(val <= mid) {
            if(no.esq == NULL)
                no.esq = new node();
            update(*no.esq, l, mid, val);
        }else {
            if(no.dir == NULL)
                no.dir = new node();
            update(*no.dir, mid+1, r, val);
        }
        no.val = 0;
        if(no.esq != NULL)
            no.val += no.esq->val;
        if(no.dir != NULL)
            no.val += no.dir->val;
    }
}
 
ll query(node &no, ll l, ll r, ll x, ll y) {
    if(l >= x && r <= y) {
        return no.val;
    } else if(r < x || l > y) return 0;
    else {
        ll mid = (l+r)>>1;
        ll resp = 0;
        if(no.esq != NULL)
            resp += query(*no.esq, l, mid, x, y);
        if(no.dir != NULL)
            resp += query(*no.dir, mid+1, r, x, y);
        return resp;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    node tree;
}
