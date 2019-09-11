#include <bits/stdc++.h>

#define ll long long

#define MOD 1000000007

using namespace std;

ll mul(ll a, ll b) {
    return ((a%MOD)*(b%MOD))%MOD;
}

ll add(ll a, ll b) {
    return ((a%MOD)+(b%MOD))%MOD;
}

struct Matrix {
    int rows, cols;
    int **mat;

    void init() {
        mat = new int*[rows];
        for(int i = 0; i < rows; i++)
            mat[i] = new int[cols];
    }
    void clean() {
        for(int i = 0; i < rows; i++)
            delete [] mat[i];
        delete [] mat;
    }

    Matrix(int row, int col) : rows(row), cols(col) {
        init();
        for(int i = 0; i < rows; i++)
            memset(mat[i], 0, cols * sizeof(int));
    }

    Matrix(const Matrix &o) : rows(o.rows), cols(o.cols) {
        init();
        for(int i = 0; i < rows; i++)
            memcpy(mat[i], o.mat[i], cols * sizeof(int));
    }

    Matrix& operator = (const Matrix &o) {
        clean();
        rows = o.rows; cols = o.cols;
        init();
        for(int i = 0; i < rows; i++)
            memcpy(mat[i], o.mat[i], cols * sizeof(int));
        return *this;
    }

    Matrix operator % (Matrix b) const {
        assert(cols == b.rows);
        Matrix c = {rows, b.cols};
        int lin = rows;
        int col = b.cols;
        for(int i = 0; i < lin; i++) {
            for(int j = 0; j < col; j++) {
                for(int k = 0; k < cols; k++) {
                    c.mat[i][j] = add(c.mat[i][j], mul(mat[i][k], b.mat[k][j]));
                }
            }
        }
        return c;
    }

    Matrix operator ^ (ll exp) const {
        Matrix ret = Matrix(rows, cols), base = *this;
        for(int i = 0; i < rows; i++) ret.mat[i][i] = 1;

        while(exp) {
            if(exp & 1) ret = ret % base;
            exp >>= 1;
            if(exp) base = base % base;
        }
        return ret;
    }

    ~Matrix() {clean();}
};

int main() {
}
