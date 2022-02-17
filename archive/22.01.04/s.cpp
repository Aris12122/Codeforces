#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()

const int N = 1e4;
bool have[N][2]; //[0] - "..", [1] - "..."
tuple <int,int,int> pos[N][2];

void solve() {
    int n, m; cin >> n >> m;
    vector<bool> dp(m+1, false);
    vector<int> pr(m+1);
    vector<string> cache;
    dp[0] = true;

    forn(i, n) {
        string s; cin >> s;
        forn(j, m) {
            string t;
            t += s[j];
            for(int k = 1; k <= 2; k++) {
                if (k + j >= m) break;
                t += s[j+k];
                int x = stoi(t);

                if (!have[x][k-1]) {
                    have[x][k-1] = true;
                    pos[x][k-1] = make_tuple(j, j+k, i);
                    cache.push_back(t);
                }
                
            }
        }
    }
    
    string s; cin >> s;
    forn(i, m) {
        string t;
        t += s[i];
        for (int k = 1; k <= 2; k++) {
            if (i - k < 0) break;
            t = s[i-k] + t;
            int x = stoi(t);
            if (have[x][k-1] && dp[i-k]) {
                dp[i+1] = true;
                pr[i+1] = i-k;
            }
            if (dp[i+1]) break;
        }
    }
    for (string t : cache) {
        have[stoi(t)][sz(t) - 2] = false;
    }

    if (!dp[m]) {
        cout << "-1\n";
        return;
    }
    vector<tuple<int,int,int>> ans;

    for (int k = m; k > 0; ) {
        int p = pr[k];
        string t = s.substr(p, k - p);
        ans.emplace_back(pos[stoi(t)][sz(t) - 2]);
        k = p;
    }

    cout << sz(ans) << '\n';
    reverse(ans.begin(), ans.end());
    for (auto [l,r,i] : ans) cout << l+1 << ' ' << r+1 << ' ' << i+1 << '\n';
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}
