#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()


int n,m;
vector<string> phones;
string s;
vector<tuple<int,int,int>> ans;

tuple<int,int,int> find(string t) {
    
    forn(i, n) {
        forn(j, m - sz(t) + 1) {
            if (phones[i].substr(j, sz(t)) == t) {
                return make_tuple(j, j + sz(t) - 1, i);
            }
        }
    }
    return make_tuple(-1,-1,-1);
}

bool rec(int pos = 0) {
    // cout << pos << endl;
    if (pos == m) {
        cout << sz(ans) << '\n';
        for (auto [l,r,i] : ans) {
            cout << l+1 << ' ' << r+1 << ' ' << i+1 << '\n';
        }
        
        return true;
    }
    string t;
    t += s[pos];
    for (int k = 1; k < m - pos; k++) {
        t += s[pos+k];
        auto[l,r,i] = find(t);
        if (l == -1) continue;
        ans.emplace_back(l,r,i);
        if (rec(pos + k + 1)) return true;
        ans.pop_back();
    }
    return false;
}


void solve() {
    cin >> n >> m;
    ans.clear();
    phones.resize(n);

    forn(i, n) 
        cin >> phones[i];
    cin >> s;
    if (!rec()) {
        cout << "-1\n";
    }
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}
