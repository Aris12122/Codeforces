#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back

int ask(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    int x; cin >> x;
    return x;
}

void solve() {
    int n; cin >> n;
    for (int i = 2; i < n; i++) {
        if (ask(1, i) == -1) {
            cout << "! " << i-1 << endl;
            return;
        }
    }
}

int main() {
    solve();
}
