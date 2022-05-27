#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back



void solve() {
    int n,m; cin >> n >> m;
    vector<int> a(n);
    for (auto &e:a) cin >> e;
    for (int iq = 0; iq < m; iq++) {
        {
            int i,x; cin >> i >> x;
            a[i-1] += x;
        }

        int ans = 1;
        int pr = a[0];
        for (int i = 1; i < n; i++) {
            int cur = min(pr, a[i]);
            if (cur != pr) {
                ans++;
            }
            pr = cur;
        }
        cout << ans << endl;
    }
}

int main() {
    solve();
}
