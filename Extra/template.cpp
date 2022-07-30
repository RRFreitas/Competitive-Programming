#include "bits/stdc++.h"

using namespace std;

#ifdef EBUG
#include "trace.h"
#else
#define trace(...) assert(true)
#define recInit(...) assert(true)
#define recEnd(...) assert(true)
#define recInfo(...) assert(true)
#define trace2(...) assert(true)
#endif

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int) (x.size())

const long long INF = 1e18;
const long long MOD = 1e9 + 7;

int clz(unsigned long long N) {
    return N ? 63 - __builtin_clzll(N) : -1;
}

void solvetask() {

}

int main() {
    ios_base::sync_with_stdio(false);
#ifndef EBUG
    cin.tie(0);
#endif

    int t = 1;
    cin >> t;

    while(t--) solvetask();
}
