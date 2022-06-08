#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back



void solve() {
    int n; cin >> n;
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b < a; b++) {
            int c = n - a - b;
            if (b > c && c >= 1) {
                cout << b << ' ' << a << ' ' << c << '\n';
                return;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}
