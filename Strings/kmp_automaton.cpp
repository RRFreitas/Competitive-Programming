#include "bits/stdc++.h"

using namespace std;

struct KMP {

    vector<int> s;
    vector<int> pf;
    vector<vector<int>> automaton;
    bool is_built = false;

    KMP(string &_s) {
        s = vector<int>(_s.begin(), _s.end());
    }

    KMP(vector<int> _v) {
        s = vector<int>(_v.begin(), _v.end());
    }

    KMP() {
        s = vector<int>();
    }

    void build() {
        pf = vector<int>(s.size());
        pf[0] = 0;

        for(int i = 1; i < s.size(); i++) {
            int k = i-1;
            while(k > 0 && s[i] != s[pf[k]]) k = pf[k-1];
            pf[i] = (s[i] == s[pf[k]] ? pf[k]+1 : 0);
        }
        is_built = true;
    }

    // build automaton with alphabet in range [start, end], e.g, ['a', 'z']
    void build_automaton(int start, int end) {
        assert(end >= start);
        assert(is_built);
        int alp_size = end-start+1;
        automaton = vector<vector<int>>(s.size(), vector<int>(alp_size, 0));
        for(int i = 0; i < alp_size; i++) automaton[0][i] = 0;
        automaton[0][s[0]-start] = 1;
        for(int i = 1; i < s.size(); i++) {
            for(int j = 0; j < alp_size; j++) {
                if(j == s[i]-start) {
                    automaton[i][j] = i+1;
                } else {
                    int k = i-1;
                    while(k > 0 && start+j != s[pf[k]]) k = pf[k-1];
                    automaton[i][j] = (start+j == s[pf[k]] ? pf[k]+1 : 0);
                }
            }
        }
    }

    void add(int v) {
        if(s.empty()) {
            pf.push_back(0);
        } else {
            int k = int(s.size()) - 1;
            while(k > 0 && v != s[pf[k]]) k = pf[k-1];
            pf.push_back((v == s[pf[k]] ? pf[k]+1 : 0));
        }
        s.push_back(v);
    }

};

int main() {
    string s;
    cin >> s;
    KMP kmp = KMP(s);
    kmp.build();
    kmp.build_automaton('a', 'z');
}
