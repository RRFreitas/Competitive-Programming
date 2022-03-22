#define trace21(arg1) trace(#arg1":", arg1)
#define trace22(arg1, arg2) trace(#arg1":", arg1, #arg2":", arg2)
#define trace23(arg1, arg2, arg3) trace(#arg1":", arg1, #arg2":", arg2, #arg3":", arg3)
#define trace24(arg1, arg2, arg3, arg4) trace(#arg1":", arg1, #arg2":", arg2, #arg3":", arg3, #arg4":", arg4)
#define trace25(arg1, arg2, arg3, arg4, arg5) trace(#arg1":", arg1, #arg2":", arg2, #arg3":", arg3, #arg4":", arg4, #arg5":", arg5)
#define trace26(arg1, arg2, arg3, arg4, arg5, arg6) trace(#arg1":", arg1, #arg2":", arg2, #arg3":", arg3, #arg4":", arg4, #arg5":", arg5, #arg6":", arg6)
#define trace27(arg1, arg2, arg3, arg4, arg5, arg6, arg7) trace(#arg1":", arg1, #arg2":", arg2, #arg3":", arg3, #arg4":", arg4, #arg5":", arg5, #arg6":", arg6, #arg7":", arg7)
#define trace28(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) trace(#arg1":", arg1, #arg2":", arg2, #arg3":", arg3, #arg4":", arg4, #arg5":", arg5, #arg6":", arg6, #arg7":", arg7, #arg8":", arg8)
#define trace29(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) trace(#arg1":", arg1, #arg2":", arg2, #arg3":", arg3, #arg4":", arg4, #arg5":", arg5, #arg6":", arg6, #arg7":", arg7, #arg8":", arg8, #arg9":", arg9)
#define trace20(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg0) trace(#arg1":", arg1, #arg2":", arg2, #arg3":", arg3, #arg4":", arg4, #arg5":", arg5, #arg6":", arg6, #arg7":", arg7, #arg8":", arg8, #arg9":", arg9, #arg0":", arg0)
#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,_9,_0,NAME,...) NAME
#define trace2(...) GET_MACRO(__VA_ARGS__, trace20, trace29, trace28, trace27, trace26, trace25, trace24, trace23, trace22, trace21)(__VA_ARGS__)

template <typename T, typename S> 
ostream& operator<<(ostream& os, const pair<T, S>& v) 
{ 
    os << "("; 
    os << v.first << ", " 
       << v.second << ")"; 
    return os; 
} 

template <typename T> 
ostream& operator<<(ostream& os, const vector<T>& v) 
{ 
    os << "["; 
    for (int i = 0; i < (int)v.size(); ++i) { 
        os << v[i]; 
        if (i != (int)v.size() - 1) 
            os << ", "; 
    } 
    os << "]"; 
    return os; 
}

template <class T, size_t N>
ostream& operator<<(ostream& os, const array<T, N>& v) 
{ 
    os << "["; 
    for (int i = 0; i < (int) N; i++) { 
        os << v[i]; 
        if (i != (int)N - 1) 
            os << ", "; 
    } 
    os << "]"; 
    return os; 
}

template <typename T> 
ostream& operator<<(ostream& os, const set<T>& v) 
{ 
    os << "{"; 
    for (auto it : v) { 
        os << it; 
        if (it != *v.rbegin()) 
            os << ", "; 
    } 
    os << "}"; 
    return os; 
}

template <typename T, typename S> 
ostream& operator<<(ostream& os, const map<T, S>& v) 
{ 
    os << "{"; 
    for (auto it : v) {
        os << "(" << it.first << " : "  << it.second << ")"; 
        if (it != *v.rbegin()) 
            os << ", ";
    } 
    os << "}";
    return os; 
}


// Trace dinâmico
void trace() { cout << endl; }
template<typename T, typename... Args>
void trace(T a, Args... args) { cout << a << " "; trace(args...); }

// Debugador de recursão
int recNum = 0;
void prTabs() { for (int ids = 0; ids < recNum; ++ids) cout << "    "; }
template<typename... Args>
void recInit(Args... args) { prTabs(); trace("rec(", args..., ")"); recNum++; }
template<typename... Args>
void recEnd(Args... args) { prTabs(); trace("->", args...); recNum--;}
template<typename... Args>
void recInfo(Args... args) { prTabs(); trace(": ", args...);}
