#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back

template<class T> bool ckmin(T &a, T b) {return a > b ? a=b, true: false;}

int n,k;
string ans, mn;

bool rec(string cur, int i) {
    ckmin(ans, cur);
    if (ans == mn) return true;
    if (i == k) {
        return false;
    }

    for (char c = 'b'; c <= 'z'; c++) if (count(all(cur),c)) {
        string nw = cur;
        for (char &e:nw) if (e == c) {
            e = char(c-1);
        }
        if (rec(nw, i + 1)) return true;
    }
    return false;
}

void solve() {
    cin >> n >> k;
    string s; cin >> s;

    mn = "";
    for (int i = 0; i < n; i++) {
        mn += 'a';
    }

    ans = s;    
    rec(s, 0);
    cout << '\n' << ans << '\n';
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}
