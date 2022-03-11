#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define eb emplace_back
#define mt make_tuple

const int INF = INT_MAX >> 1;
const int mod = 1e9 + 7;

void csum(int &a,int b) {
    a = (a + b) % mod;
}

int s, t;
vector<int> us;
vector<int> dist;
vector<int> dp[2];
int bfs(vector<vector<int>> &g) {
    queue<tuple<int,int,int>> q;
    q.push(mt(s, 0, 0)); //[v, dist, count]

    int ans = 0, mnd = INF;
    us[s] = 1;
    dp[0][s] = 1;
    dist[s] = 0;
    while(!q.empty()) {
        auto [v,d, x] = q.front(); q.pop();
        // cerr << v << ' ' << d << ' ' << dp[x][v] << endl;
        if (v == t) {
            if (mnd == INF) {
                mnd = d;
            }
            csum(ans, dp[x][v]);
        }
        if (d == mnd + 1) continue;
        for (int to : g[v]) if(d <= dist[to]) {
            dist[to] = min(dist[to], d+1);
            csum(dp[d - dist[to] + 1][to], dp[x][v]);
            // cerr << "TO: " <<  to << ' ' << dist[to] << ' ' << d << endl;
            if(us[to] == 0 || (us[to] == 1 && dist[to] == d)) q.push(mt(to, d+1, us[to]++));
        }
    }
    return ans;
}


void solve() {
    int n,m; cin >> n >> m;
    cin >> s >> t;
    us.resize(n+1);
    dp[0].resize(n+1);
    dp[1].resize(n+1);
    dist.resize(n+1);
    forn(i, n+1) {
        us[i] = dp[0][i] = dp[1][i] = 0;
        dist[i] = INF;
    }

    vector<vector<int>> g(n+1);
    forn(i, m) {
        int a,b; cin >> a >> b;
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
