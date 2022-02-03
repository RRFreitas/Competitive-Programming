/*
 *  Hash 0-indexed
 */
#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100007; // max string size
const int HMAX = 2; // number of hashes

long long inverse(int a, int b, int s0 = 1, int s1 = 0) {
    return b == 0 ? s0 : inverse(b, a%b, s1, s0-s1*(a/b));
}

long long base[HMAX] = {317, 307};
long long mod[HMAX] = {104000717, 104000711};
long long power[HMAX][NMAX], inv[HMAX][NMAX];
bool isBuilt = false;

void init() {
    for(int i = 0; i < HMAX; i++) {
        power[i][0] = inv[i][0] = 1;
        power[i][1] = base[i];
        inv[i][1]  = inverse(base[i], mod[i]);
    }
    for(int i = 2; i < NMAX; i++) {
        for(int j = 0; j < HMAX; j++) {
            power[j][i] = (power[j][i-1] * base[j]) % mod[j];
            inv[j][i] = (inv[j][i-1]*inv[j][1]) % mod[j];
        }
    }
    isBuilt = true;
}

struct Hash {
    vector<vector<long long>> h = vector<vector<long long>>(HMAX, vector<long long>());
    int _n;

    Hash() {
        _n = 0;
    }

    Hash(string &s) {
        _n = 0;
        for(char c : s) {
            add(c);
        }
    }

    void add(char c) {
        assert(isBuilt);
        for(int i = 0; i < HMAX; i++) {
            h[i].push_back(((_n == 0 ? 0 : h[i][_n-1]) + c * power[i][_n]) % mod[i]);
        }
        _n++;
    }

    array<long long, HMAX> sub(int l, int r) {
        assert(isBuilt);
        assert(r < _n);
        array<long long, HMAX> ans{};
        for(int i = 0; i < HMAX; i++) {
            ans[i] = ((h[i][r] - (l == 0 ? 0 : h[i][l-1])) * inv[i][l]) % mod[i];
            if(ans[i] < 0) ans[i] += mod[i];
        }
        return ans;
    }
};
