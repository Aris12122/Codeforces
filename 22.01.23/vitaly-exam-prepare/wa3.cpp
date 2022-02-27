#include <bits/stdc++.h>

#define F first
#define S second 

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

const int INF = 1e9;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), e(m), t(m), p(m);
    for (int& x : a) cin >> x;
    
    vector<vi> ord(n);
    vector<int> ans;

    ll ts = 0;
    for (int i = 0; i < m; ++i) {
        cin >> e[i] >> t[i] >> p[i];
        ord[--e[i]].push_back(i);
    }

    for (int i = 0; i < n; ++i) {
        int vc = 0;
        
        vector<int> dp(200, INF); dp[0] = 0;
        vector<int> par, val;
        vector<int> state(200, -1);
        for (int j : ord[i]) {
            for (int s = 100; s--; ) {
                if (ckmin(dp[s+p[j]], dp[s] + t[j])) {
                    val.push_back(j);
                    par.push_back(state[s]);
                    state[s+p[j]] = vc++;
                }
            }
        }

        int s = min_element(dp.begin()+100, dp.end()) - dp.begin();

        if (ts + dp[s] > a[i]) {
            cout << -1 << '\n';
            return;
        }

        ts += dp[s];
        for (int v = state[s]; v != -1; v = par[v]) {
            ans.push_back(val[v]+1);
        }
    }

    cout << ans.size() << '\n';
    for (int x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1; 
    cin >> t;
    while (t--) solve();
}