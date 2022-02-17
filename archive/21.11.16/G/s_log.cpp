#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
 
const int N = 1e6 + 50;
string a[N];

int n,m;
int ans;

void solve(int sum0) {
    set<int> v;
    for (int sum = sum0, ad = 0; sum < n + m; sum += 2, ad++) {
        int li = max(0, sum - m + 1), ri = min(n - 1, sum);
        if (li > ri) continue;

        for (int i = li; i <= ri; i++) {
            int j = sum - i;

            if (a[i][j] == '1') {
                if (v.empty()) {
                    v.insert(i - ad);
                    ans++;
                    continue;
                }
                
                auto it = v.upper_bound(i - ad);
                if (it-- == v.begin()) {
                    ans++;
                    v.insert(i - ad);
                } else {
                    v.erase(it);
                    v.insert(i - ad);
                }
            }
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
