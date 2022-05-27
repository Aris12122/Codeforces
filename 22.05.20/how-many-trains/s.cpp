#include <bits/stdc++.h>
 
using namespace std;

template<class T> bool ckmin(T &a, T b) {return a > b ? a=b, true : false;}
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back


const int N = 1e5 + 500;
const int sz = 320;

int a[N];
int v[N];
bool first[N];

int ans = 0;

int gr(int i) {
    return i / sz;
}

int set_gr[sz];
int ans_gr[sz];
int mn_gr[sz];

int get_val(int i) {
    if (i < 0) return INT_MAX;
    return set_gr[gr(i)] == 0 ? v[i] : set_gr[gr(i)];
}

void set_val(int k) {
    if (set_gr[k] == 0) return;
    ans -= ans_gr[k];
    ans_gr[k] = 0;
    for (int i = k*sz; i < (k+1)*sz; i++) {
        v[i] = set_gr[k];
        first[i] = false;
    }
    int i = k * sz;
    if (v[i] < get_val(i-1)) first[i] = true, ans++, ans_gr[k] = 1;
    set_gr[k] = 0;
}

void cnt_min(int k) {
    mn_gr[k] = INT_MAX;
    for (int i = k*sz; i < (k+1)*sz; i++) {
        ckmin(mn_gr[k], a[i]);
    }
}

void solve() {
    int n,m; cin >> n >> m;
    
    
    forn(i, n) 
        cin >> a[i];

    v[0] = a[0];
    forn(i, n-1)
        v[i+1] = min(a[i+1], v[i]);

    first[0] = true, ans++;
    ans_gr[0] = 1;
    forn(i, n-1) { 
        if (v[i] < v[i-1]) {
            first[i] = true, ans++;
            ans_gr[gr(i)]++;
        }
    }

    
    forn(iq, m) {
        int i,x; cin >> i >> x;
        a[--i] += x;

        cnt_min(gr(i));
        set_val(gr(i));

        v[i] = min(a[i], get_val(i-1));

        bool ok = false;

        for (int j = i+1; gr(j) == gr(i) && j < n; j++) {
            if (a[j] < v[i]) {
                ok = true;
                if (!first[j]) first[j] = true, ans++;
                break;
            }
            v[j] = v[i];
            if (first[j]) ans--, first[j] = false;
        }

        if (ok) {
            cout << ans << endl;
            continue;
        }

        for (int k = gr(i)+1; k*sz < n; k++) {
            if (mn_gr[k] < v[i]) {
                set_gr[k] = 0;
                for (int j = k*sz; j < (k+1)*sz && j < n; k++) {
                    if (a[j] < v[i]) {
                        if (!first[j]) first[j] = true, ans++;
                        break;
                    }
                    v[j] = v[i];
                    if (first[j]) ans--, first[j] = false;
                }
                break;
            }
            ans -= ans_gr[k];
            ans_gr[k] = 0;
            set_gr[k] = v[i];
        }

        cout << ans << endl;
    }


}

int main() {
    solve();
}
