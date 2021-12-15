vector<string> split(string &s, string delim=" ") {
    vector<string> res;
    size_t last = 0;
    size_t next = 0;
    while ((next = s.find(delim, last)) != string::npos) {
        res.emplace_back(s.substr(last, next-last));
        last = next + 1;
    }
    res.emplace_back(s.substr(last));
    return res;
}
