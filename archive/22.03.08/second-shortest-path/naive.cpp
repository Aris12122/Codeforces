#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define eb emplace_back

const int mod = 1e9 + 7;
const int INF = INT_MAX >> 1;

int mnd;
int s, t;
int bfs(vector<vector<int>> &g) {
    queue<pair<int,int>> q;
    q.push({s, 0});
    mnd = INF;
    int ans = 0;
    while(!q.empty()) {
        auto [v,d] = q.front(); q.pop();
        // cerr << v << ' ' << d << endl;
        if (v == t) {
            ans = (ans + 1) % mod; 
            if (mnd == INF) mnd = d;
        }
        if (d == mnd + 1) continue;
        for (int to : g[v]) {
            q.push({to, d+1});
        }
    }
    // cerr << mnd << ' ' << endl;
    return ans;
}


void solve() {
    int n,m; cin >> n >> m;
    cin >> s >> t, s--, t--;

    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a,b; cin >> a >> b, a--, b--;
        g[a].eb(b);
        g[b].eb(a);
    }
    cout << bfs(g) << '\n';
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}
