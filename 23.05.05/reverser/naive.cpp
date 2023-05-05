#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back


bool IsLess(const vector<int>& a, const vector<int>& b) {
    for (int i = 0; i < sz(a); ++i) {
        if (a[i] < b[i]) return true;
        else if (a[i] > b[i]) return false;
    }
    return false;
}

vector<int> oper(const vector<int>& p, int l, int r) {
    vector<int> res;
    for (int i = r + 1; i < sz(p); ++i) {
        res.eb(p[i]);
    }
    for (int i = r; i >= l; --i) {
        res.eb(p[i]);
    }
    for (int i = 0; i < l; ++i) {
        res.eb(p[i]);
    }
    return res;
}

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for (auto &e : p) cin >> e;

    vector<int> ans(n, 0);


    for (int l = 0; l < n; ++l) {
        for (int r = l; r < n; ++r) {
            vector<int> cur = oper(p, l, r);
            if (IsLess(ans, cur)) {
                ans = cur;
                // cerr << l << ' ' << r << endl;
            }
        }
    }
    for (auto e : ans) cout << e << ' ';
    cout << '\n';
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}
