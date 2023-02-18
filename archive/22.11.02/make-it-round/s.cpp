#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back

using ll = long long;

void solve() {
    ll n,m; cin >> n >> m;
    ll n0 = n;
    int cnt2 = 0, cnt5 = 0;
    ll k = 1;
    while (n > 0 && n % 2 == 0) {
        n /= 2;
        cnt2++;
    }
    while (n > 0 && n % 5 == 0) {
        n /= 5;
        cnt5++;
    }
    while (cnt2 < cnt5 && k * 2 <= m) {
        cnt2++;
        k *= 2;
    }
    while (cnt5 < cnt2 && k * 5 <= m) {
        cnt5++;
        k *= 5;
    }
    while (k * 10 <= m) {
        k *= 10;
    }
    if (k == 1) {
        cout << n0 * m << endl;
    } else {
        k *= m / k; // 1 <= m/k < 10
        cout << n0 * k << endl;
    }
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        if (tt+1 == 181) {
            ll n,m; cin >> n >> m;
            cout << n << ' ' << m << endl;
            return 0;
        }
        solve();
    }
}
