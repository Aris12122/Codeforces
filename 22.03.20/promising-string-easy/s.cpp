#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back


struct my_set{
    vector <vector <int>> v;
    int n;
    my_set(): v(20), n(0){}

    void push(int x){
        //O(n&-n) - request,
        //~O(NlogN),small const
        v[0].eb(x), n++;
        if(sz(v[0]) > 1) sort(all(v[0]));

        for(int i=0;sz(v[i]) > (1<<i);i++){
            if(v[i+1].empty()) swap(v[i],v[i+1]);
            else{
                vector <int> res(sz(v[i]) + sz(v[i+1]));
                merge(all(v[i]),all(v[i+1]),res.begin());
                res.swap(v[i+1]); vector <int> ().swap(v[i]);
            }
        }
    }

    int count_lower(int x) const {
        //O(log(logn!)) - request ~~ O(logn)
        int res = 0;
        for(auto &e:v) res += (int)(lower_bound(all(e),x) - e.begin());
        return res;
    }
};



inline int ost(int x) {
    return (x % 3 + 3) % 3;
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    my_set v[3];

    int cur = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        v[ost(cur)].push(cur);

        if (s[i] == '-') cur++;
        else cur--;

        ans += v[ost(cur)].count_lower(cur + 1);
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}
