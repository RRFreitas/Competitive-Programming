#define MOD 1000000007

ll mul(ll a, ll b) {
    return ((a%MOD)*(b%MOD))%MOD;
}

ll add(ll a, ll b) {
    return ((a%MOD)+(b%MOD))%MOD;
}

struct Matrix {
    ll **m, rows, cols;

    void init() {
        m = new ll*[rows];
        for(ll i = 0; i < rows; i++)
            m[i] = new ll[cols];
    }

    void clean() {
        for(int i = 0; i < rows; i++)
            delete [] m[i];
        delete [] m;
    }
    
    void ident() {
        for(int i = 0; i < min(rows,cols); i++)
            m[i][i] = 1;
    }

    Matrix(int row, int col) : rows(row), cols(col) {
        init();
        for(int i = 0; i < rows; i++)
            memset(m[i], 0, cols * sizeof(ll));
    }

    Matrix(const Matrix &o) : rows(o.rows), cols(o.cols) {
        init();
        for(int i = 0; i < rows; i++)
            memcpy(m[i], o.m[i], cols * sizeof(ll));
    }

    Matrix& operator = (const Matrix &o) {
        clean();
        rows = o.rows;
        cols = o.cols;
        init();
        for(int i = 0; i < rows; i++)
            memcpy(m[i], o.m[i], cols * sizeof(ll));
        return *this;
    }

    Matrix operator % (Matrix o) const {
        assert(cols == o.rows);
        Matrix res = Matrix(rows, o.cols);
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < o.cols; j++) {
                for(int k = 0; k < cols; k++) {
                    res.m[i][j] = add(res.m[i][j], mul(m[i][k], o.m[k][j]));
                }
            }
        }
        return res;
    }

    Matrix operator ^ (ll exp) const {
        Matrix res = Matrix(rows, cols), base = *this;
        res.ident();

        while(exp) {
            if(exp & 1) res = res % base;
            exp >>= 1;
            if(exp) base = base % base;
        }
        return res;
    }

    ~Matrix() {clean();}
};
