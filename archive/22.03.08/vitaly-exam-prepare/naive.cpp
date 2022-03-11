#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()

struct option {
    int e,t,p;
    option() {

    }

    option(int _e, int _t, int _p) : e(_e), t(_t), p(_p) {

    }
};

void solve() {
    int n,m; cin >> n >> m;
    vector<int> a(n);
    forn(i, n) {
        cin >> a[i];
    }
    vector<option> v(m);

    forn(j, m) {
        int e,t,p; cin >> e >> t >> p, e--;
        v[j] = option(e,t,p);
    }

    for (int mask = 0; mask < (1 << m); mask++) {
        vector<int> cur;
        for (int i = 0; i < m; i++) if (mask >> i & 1) {
            cur.emplace_back(i);
        }

        bool ok;
        do {
            ok = true;
            vector<int> curp(n, 0);
            int curt = 0, curi = 0;
            for (int i = 0; i < sz(cur); i++) {
                auto [e,t,p] = v[cur[i]];
                curt += t;
                while (curi < n && curt > a[curi]) {
                    ok &= curp[curi] >= 100;
                    curi++;
                }
                curp[e] += p;
            }
            while (curi < n) {
                ok &= curp[curi] >= 100;
                curi++;
            }
            if (ok) break;

        } while (next_permutation(all(cur)));

        if (ok) {
            cout << sz(cur) << '\n';
            for (auto e:cur) cout << e+1 << ' ';
            cout << '\n';
            return;
        }
    }
    cout << "-1\n";
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}
