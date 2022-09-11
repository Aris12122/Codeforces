#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

using ll = long long;
using ld = long double;

template<class T> bool ckmin(T &a,T b) { return b < a ? a=b, true : false;}
template<class T> bool ckmax(T &a,T b) { return a < b ? a=b, true : false;}

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define sz(v) (int)v.size()

const int N = 2e5 + 500;
const int INF = INT_MAX >> 1;
const ll LINF = LLONG_MAX >> 1;
const int mod = 1e9 + 7;

//mt19937 rng(58);
//uniform_int_distribution dis;


signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cout<<fixed<<setprecision(20);
    vector<long long> v = {};
    
    for(int i = 0; i < 15; ++i) {
        v.eb(rnd.next((ll)1e9, (ll)1e18L));
    }

    // vector<int> l = {10, 20, 100, 500, 1000, 5000, 10000, 50000, 100000, 200000};

    sort(all(v));

    pattern p("[a-z]|[0-9]");
    for (int i = 0; i < sz(v); i++) {
        string s;
        for (int j = 0; j < 40; j++) {
            s += p.next(rnd);
        }
        cout << "g0 " << v[i] << ' ' << s << " > $\n";
    }

    return 0;
}
// 857f10dbae670f33461bdf95522807964c9f40ba