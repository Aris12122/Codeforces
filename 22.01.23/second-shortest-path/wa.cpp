#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
//#define double long double
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

const int MOD = 1e9 + 7;
const int maxN = 5e3 + 1;
const int INF = 2e9;
const int MB = 20;

vector<int> get(int n, int m, int s, vector<vector<int>>& g) {
    queue<int> q;
    q.push(s);
    vector<int> d(n, n);
    d[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : g[v]) {
            if (d[u] > d[v] + 1) {
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }
    return d;
}

vector<vector<int>> get(int n, int m, vector<vector<int>>& g, vector<int>& d1, vector<int>& d2, int s) {
    queue<int> q;
    q.push(s);
    int len = d2[s];
    vector<vector<int>> ng(n);
    vector<bool> used(n);
    used[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : g[v]) {
            if (d1[v] + d2[u] + 1 == len) {
                ng[v].push_back(u);
            }
            if (!used[u]) {
                q.push(u);
                used[u] = true;
            }
        }
    }
    return ng;
}

void dfs(int v, vector<int>& sz, vector<int>& h, vector<vector<int>>& g) {
    if (g[v].empty()) {
        sz[v] = 1;
        return;
    }
    for (int u : g[v]) {
        h[u] = h[v] + 1;
        dfs(u, sz, h, g);
        sz[v] += sz[u];
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    int s, t;
    cin >> s >> t;
    --s;--t;
    vector<vector<int>> g(n);
    for (int i = 0;i < m; ++i) {
        int v, u;
        cin >> v >> u;
        --v;--u;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    auto d1 = get(n, m, s, g);
    auto d2 = get(n, m, t, g);

    auto ng = get(n, m, g, d1, d2, s);
    vector<int> sz(n);
    vector<int> h(n, -1);
    h[0] = 0;
    dfs(s, sz, h, ng);
    int ans = sz[s];
    int len = d1[t];
    for (int i = 0; i < n; ++i) {
        for (int u : g[i]) {
            if (d1[i] + d2[u] + 1 == len + 1) {
                ans = (ans + sz[u]) % MOD;
            }
        }
    }
    cout << ans % MOD << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //    srand(time(0));
    int t = 1;
    cin >> t;
    while (t--) solve();
}