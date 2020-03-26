#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ll long long
#define pi pair<int,int>

using namespace std;

vector<int> SA(string s) {
    s += '$';
    int n = s.size();
    int tam = max(n, 256);
    vector<int> p(n), c(tam), cn(tam), cnt(tam, 0), pn(n);
    for(int i = 0; i < n; i++) cnt[s[i]]++;
    for(int i = 1; i < tam; i++) cnt[i] += cnt[i-1];
    for(int i = n-1; i >= 0; i--) p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classe = 0;
    for(int i = 1; i < n; i++) {
        if(s[p[i]] != s[p[i-1]])
            classe++;
        c[p[i]] = classe;
    }

    for(int k = 1; k < n; k <<= 1) {
        for(int i = 0; i < n; i++) {
            pn[i] = p[i] - k;
            if(pn[i] < 0) pn[i] += n;
        }
        fill(cnt.begin(), cnt.end(), 0);
        for(int i = 0; i < n; i++) cnt[c[pn[i]]]++;
        for(int i = 1; i < tam; i++) cnt[i] += cnt[i-1];
        for(int i = n-1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];

        cn[p[0]] = 0;
        classe = 0;
        for(int i = 1; i < n; i++) {
            pi atual = MP(c[p[i]], c[(p[i]+k) % n]);
            pi ant = MP(c[p[i-1]], c[(p[i-1]+k) % n]);
            if(atual != ant) classe++;
            cn[p[i]] = classe;
        }
        c.swap(cn);
    }
    return p;
}

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    vector<int> suf = SA(s);
    for(int i = 1; i < suf.size(); i++) cout << suf[i] << "\n";
}
