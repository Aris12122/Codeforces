#include <bits/stdc++.h>

using namespace std;

#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back


void slow_solve(int n, string s, string t) {
    set<string> was;

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

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    string t; cin >> t;

    if (n <= 6) {
        slow_solve(n, s, t);
        return;
    }
    map<char, int> cnt;
    for (char c : s) {
        cnt[c]++;
    }

    for (char c : t) {
        cnt[c]--;
    }

    bool ok = true;
    for (auto [c, x] : cnt) {
        ok &= x == 0;
    }
    cout << (ok ? "Yes" : "No") << '\n';
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
