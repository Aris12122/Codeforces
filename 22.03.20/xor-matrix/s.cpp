#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back

const int INF = INT_MAX >> 1;

void solve() {
    int n; cin >> n;
    int cnt1 = 0;
    vector<int> cnt (n, 0);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0, k = (n - i) % n; j < n; j++, k = (k + 1 == n ? 0 : k + 1)) if (s[j] == '1') {
            cnt1++;
            cnt[k]++;
        }
    }
    int ans = INF;
    for (int i = 0; i < sz(cnt); i++) {
        ans = min(ans, cnt1 - cnt[i] + (n - cnt[i]));
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}
