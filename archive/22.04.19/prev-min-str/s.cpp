#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back

template <class T> bool ckmax(T &a, T b) {return a<b ? a=b, true : false;}


void solve() {
    int n,k; cin >> n >> k;
    string s; cin >> s;

    char mn = 'a';
    for (int i = 0; i < n; i++) if(s[i] > mn) {
        if (s[i] - 'a' > k) {
            k -= mn - 'a';
            int to = s[i] - k;
            for (char c = s[i]; c > to; c--) {
                for (char &e:s) if (e == c) {
                    e = char(c-1);
                }
            }
            break;
        } else ckmax(mn, s[i]);
    }
    for (char &e:s) if (e <= mn) {
        e = 'a';
    }
    cout << '\n' << s << '\n';
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}
