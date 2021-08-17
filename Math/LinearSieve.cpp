#include "bits/stdc++.h"

using namespace std;

const int MAX_N = 100000001; // more than N

vector<int> prime;
bool is_composite[MAX_N];
int mobius[MAX_N];

void sieve(int n) {
    fill(is_composite, is_composite + n, false);
    mobius[1] = 1;

    for(int i = 2; i <= n; i++) {
        if(!is_composite[i]) { // i is prime
            prime.push_back(i);
            mobius[i] = -1;
        }
        for(int j = 0; j < prime.size() && i*prime[j] <= n; j++) {
            is_composite[i*prime[j]] = true;
            if(i % prime[j] == 0){ // p | i
                mobius[i*prime[j]] = 0;
                break;
            } else { // p -| i    -> f(i*p) = f(i) * f(p)
                mobius[i*prime[j]] = mobius[i] * mobius[prime[j]];
            }
        }
    }
}
