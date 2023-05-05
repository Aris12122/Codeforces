#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back

using ll = long long;

const int N = 11, M = 18;

ll dp[N][M]; // dp[i][j]~--- < i * 10^j

ll lower(string x, int pw10, int i = 0) {
    if (pw10 == 1) return dp[x[i] - '0' + 1][pw10];
//    cout << x << ' ' << pw10 << ' ' << i << endl;
    if (x[i] == '4') return dp[4][pw10];
    return dp[x[i] - '0'][pw10] + lower(x, pw10 - 1, i + 1);
}

void solve() {
    ll k; cin >> k;
    ++k;

    ll l = 0, r = 1e17;
    while (r - l > 1) {
        ll m = (l + r) >> 1;
        string t = to_string(m);
        if (lower(t, sz(t)) >= k) r = m;
        else l = m;
    }
    cout << l + 1 << endl;
}

int main() {
    int t;
    cin >> t;

    dp[10][0] = 1;
    for (int lev = 1; lev <= 17; ++lev) {
        dp[1][lev] = dp[10][lev-1];
        for (int i = 2; i <= 10; ++i) {
            dp[i][lev] = dp[i-1][lev] + (i == 5 ? 0 : dp[10][lev-1]);
//            cout << i << ' ' << lev << ' ' << dp[i][lev] - 1 << endl;
        }
    }

    forn(tt, t) {
        solve();
    }
}
