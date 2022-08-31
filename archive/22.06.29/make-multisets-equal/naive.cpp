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
        a.insert(x);
    }

    forn(i, n) {
        int x; cin >> x;
        if (a.count(x)) {
            a.erase(a.find(x));
        } else {
            b.insert(x);
        }
    }
    set<multiset<int>> was;

    queue<multiset<int>> q;
    q.push(b);
    was.insert(b);
    while (!q.empty()) {
        b = q.front(); q.pop();
        // print(b);
        if (a == b) {
            cout << "YES\n";
            return;
        }
        multiset<int> t = b;
        int p = 0;
        for (auto e : b) {
            if (e == p) continue;
            p = e;
            t.erase(t.find(e));
            if (e != 1) {
                t.insert(e / 2);
                if (!was.count(t)) q.push(t);
                was.insert(t);
                t.erase(t.find(e / 2));
            }
            if (e * 2 <= INF) {
                t.insert(e * 2);
                if (!was.count(t)) q.push(t);
                was.insert(t);
                t.erase(t.find(e * 2));
            }
            t.insert(e);
        }
    }
    cout << "NO\n";
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}
