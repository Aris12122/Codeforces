#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
 
const int N = 1e6 + 50;
string a[N];

int n,m;
int ans;

void solve(int sum0) {
    vector<int> v;
    for (int sum = sum0, ad = 0, pref = 0; sum < n + m; sum += 2, ad++) {
        vector<int> cur;
        int li = max(0, sum - m + 1), ri = min(n - 1, sum);
        if (li > ri) continue;

        for (int i = li; i <= ri; i++) {
            int j = sum - i;

            if (a[i][j] == '1')
                cur.emplace_back(i);
        }

        while (pref != sz(v) && v[pref] + ad > ri) {
            pref++;
        }
        for (int i = pref; i < sz(v); i++) {
            int new_val = v[i];
            while (!cur.empty() && cur.back() - ad >= v[i]) {
                new_val = max(new_val, cur.back() - ad);
                cur.pop_back();
            }
            v[i] = new_val;
        }
        if (!cur.empty()) {
            v.emplace_back(cur.back() - ad);
            ans++;
        }
    }
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        cin >> n >> m;

        forn(i, n) {
            string s; 
            cin >> a[i];
        }

        ans = 0;
        solve(0);
        solve(1);
        
        cout << ans << '\n';
    }
}
