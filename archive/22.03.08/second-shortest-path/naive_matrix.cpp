#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define eb emplace_back

const int mod = 1e9 + 7;
const int INF = INT_MAX >> 1;

void csum(int &a,int b) {
    a = (a + (b % mod)) % mod;
}

int mul(int a, int b) {
    return int((a * 1ll * b) % mod);
}

struct matrix {
    vector<vector<int>> a;
    int n;

    matrix(int _n): n(_n) {
        a = vector<vector<int>>(n, vector<int>(n,0));
    }

    void read(int m) {
        forn(i, m) {
            int u,v; cin >> u >> v, u--, v--;
            a[u][v] = a[v][u] = 1;
        }
        forn(i, n) {
            // a[i][i] = 1;
        }
    }

    matrix operator*(const matrix &B) const {
        matrix C(n);
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                csum(C.a[i][j], mul(a[i][k],B.a[k][j]));
            }
        }
        return C;
    }

    void print() {
        forn(i, n) forn(j, n) {
            cerr << a[i][j] << (j == n-1 ? '\n' : ' ');
        }
        cerr << endl;
    }
};



void solve() {
    int n,m; cin >> n >> m;
    int s, t; cin >> s >> t, s--, t--;
    matrix T(n), cur(n);
    T.read(m);
    cur = T;
    

    int ans = 0;
    for (;;) {
        // cur.print();
        // cerr << cur.a[s][t] << endl;
        if (cur.a[s][t] > 0) {
            csum(ans, cur.a[s][t]);
            cur = cur * T;
            break;
        }
        cur = cur * T;
    }
    csum(ans, cur.a[s][t]);
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}
