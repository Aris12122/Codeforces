#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back



void solve() {
    int n; cin >> n;
    set<string> was;

    string s; cin >> s;
    string t; cin >> t;
    queue<string> q;
    q.push(s);
    was.insert(s);

    auto add = [&](string& s, int i, int j) {
        if (i >= 0 && i < j && j < n) {
            swap(s[i], s[j]);
            if (!was.count(s)) {
                was.insert(s);
                q.push(s);
            }
            swap(s[i], s[j]);
        }

    };

    while (!q.empty()) {
        s = q.front(); q.pop();
        for (int i = 0; i < n; ++i) {
            add(s, i, i+3);
            add(s, i, i+4);
            add(s, i-3, i);
            add(s, i-4, i);
        }
    }
    cout << (was.count(t) ? "Yes" : "No") << '\n';
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}
