#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back


vector<int> a;

bool can(int l, int r) {
    if (a[l] == r - l) return true;
    if (a[r] == r - l) return true;

    for (int i = l + 1; i+1 < r; ++i) {
        if (can(l, i) && can(i + 1, r)) return true;
    }
    return false;
}

void solve() {
    int n; cin >> n;
    a.resize(n);
    for (auto &e : a) cin >> e;

    cout << (can(0, n - 1) ? "YES" : "NO") << '\n';

    a.clear();
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}
