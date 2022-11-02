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

int solve() {
    for (int i = 2; i <= 8; i++) {
        int x = ask(1, i);
        int y = ask(i, 1);
        if (x == -1) return i-1;
        if (x != y) return x + y;
    }
    assert(false);
}

int main() {
    cout << "! " << solve() << endl;
}
