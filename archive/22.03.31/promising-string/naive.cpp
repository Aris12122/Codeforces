#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back

bool is_perspective(string s) {
    int minus = 0, plus = 0;
    int n = sz(s);
    forn(i, n) {
        if (s[i] == '+') plus++;
        else minus++;
    }
    for (int i = 1; i < n && minus > plus; i++) {
        if (s[i] == '-' && s[i-1] == '-') {
            s[i] = '+';
            minus -= 2;
            plus += 1;
        }
    }
    return minus == plus;
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int len = 1; len <= n - i; len++) {
            ans += is_perspective(s.substr(i, len));
        }
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}
