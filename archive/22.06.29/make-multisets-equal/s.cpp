#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back

const int INF = 1e9;

void solve() {
    int n; cin >> n;
    multiset<int> a, b;

    forn(i, n) {
        int x; cin >> x;
        while (x % 2 == 0) {
            x /= 2;
        }
        a.insert(x);
    }

    forn(i, n) {
        int x; cin >> x;
        // while (x * 2 <= INF) x *= 2;
        b.insert(x);
    }
    n = sz(a);

    while (!b.empty()) {
        int x = *b.rbegin();
        // cout << x << endl;
        if (!a.count(x)) {
            if (x == 1) break;
            b.erase(b.find(x));
            b.insert(x / 2);
        } else {
            b.erase(b.find(x));
            a.erase(a.find(x));
        }
    }

    cout << (b.empty() ? "YES" : "NO") << '\n';

}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}
