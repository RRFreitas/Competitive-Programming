vector<int> SA(string &s){
    int n = s.size(), alf = max(256, n+2);
    vector<int> ans, rnk(n), temp_rnk(n), aux[alf];

    for (int i=0; i<n; i++) rnk[i] = s[i];

    function<int (int)> gr = [&](int i){ return (i < n ? rnk[i] : -1); }; //get rank

    for (int d=1; d<=n; d <<= 1){

        ans.clear();
        for (int i=0; i<n; i++) aux[gr(i+d)+1].push_back(i);
        for (int i=0; i<alf; i++){
            for (int j=0; j<aux[i].size(); j++){
                ans.push_back(aux[i][j]);
            }
            aux[i].clear();
        }
        for (int i=0; i<n; i++) aux[gr(ans[i])].push_back(ans[i]);
        ans.clear();
        for (int i=0; i<alf; i++){
            for (int j=0; j<aux[i].size(); j++){
                ans.push_back(aux[i][j]);
            }
            aux[i].clear();
        }

        temp_rnk[ans[0]] = 0;
        for (int i=1; i<n; i++){
            temp_rnk[ans[i]] = temp_rnk[ans[i-1]] + (make_pair(gr(ans[i]), gr(ans[i]+d)) != make_pair(gr(ans[i-1]), gr(ans[i-1]+d)));
        }
        rnk = temp_rnk;
        if (rnk[ans[n-1]] == n-1) break;
    }
    
    return ans;
}

vector<int> kasai(vector<int> sa, string s){
    int n = sa.size();
    vector<int> r(n), lcp(n);
    for (int i=0; i<n; i++) r[sa[i]] = i;

    int h=0;
    for (int i=0; i<n; i++){
        if (r[i] == n-1) h = lcp[n-1] = 0;
        else{
            int j = sa[r[i] + 1];
            while(i + h < n && j + h < n && s[i+h] == s[j+h]) h++;
            lcp[r[i]] = h;
            h = max(0, h-1);
        }
    }
    return lcp;
}

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    vector<int> suf = SA(s);
    for(int i = 1; i < suf.size(); i++) cout << suf[i] << "\n";
}
