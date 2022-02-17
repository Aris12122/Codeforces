#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()

struct option {
    int i,t,p;
    option() {

    }

    option(int _i, int _t, int _p) : i(_i), t(_t), p(_p) {

    }
};

int n,m;
vector<int> curp, a;
vector<option> v;
vector<int> cur;
vector<bool> us;

long long curt;
bool fun() {
    bool ok = true;
    forn(i, n) {
        ok &= curp[i] >= 100;
    }
    if (ok) {
        cout << sz(cur) << '\n';
        for(auto e:cur) {
            cout << e + 1 << ' ';
        }
        cout << '\n';
        return true;
    }

    forn(j, m) if (!us[j]) {
        auto [i,t,p] = v[j];
        if (a[i] < curt + t && curp[i] < 100) {
            continue;
        }
        curt += t;
        us[j] = true;
        curp[i] += p;
        cur.emplace_back(j);
        if (fun()) return true;
        cur.pop_back();
        curp[i] -= p;
        us[j] = false;
        curt -= t;
    }
    return false;
}


void solve() {
    cin >> n >> m;
    a.resize(n);
    curp.resize(n);
    forn(i, n) {
        cin >> a[i];
        curp[i] = 0;
    }
    v.resize(m);
    us.resize(m);

    forn(j, m) {
        int i,t,p; cin >> i >> t >> p, i--;
        v[j] = option(i,t,p);
        us[j] = false;
    }

    curt = 0;
    cur.clear();
    cout << (fun() ? "" : "-1\n");
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}
