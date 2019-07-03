#include <bits/stdc++.h>

#define debugarr(a) for(int i : a) cout << i << " ";
#define N 8
#define LSB(i) ((i) & -(i))

// LSB = Less Significant Bit

using namespace std;

int bit[N+1]; // 1..N indexed
int arr[N] = {5,2,3,8,9,1,2,3};

int getSum(int index) {
    return index == 0 ? 0 : bit[index] + getSum(index - LSB(index));
}

void update(int i, int val) {
    if(i > N) return;
    bit[i] += val;
    update(i + LSB(i), val);
}

int query(int begin, int end) {
    return getSum(end) - getSum(begin - 1);
}

void buildBIT() {
    for(int i = 0; i < N; i++) {
        update(i+1, arr[i]);
    }
}

int main() {
    buildBIT(); 

    debugarr(bit);
    cout << endl;

    for(int i = 1; i < 100; i++) {
        update(1, i);
        cout << query(1, N) << endl;
    }
}
