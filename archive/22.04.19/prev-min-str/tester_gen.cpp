#include <bits/stdc++.h>
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
    vector<int> r = {20, 10000, 100000, 200000};
    // vector<int> l = {10, 20, 100, 500, 1000, 5000, 10000, 50000, 100000, 200000};

    vector<pair<int,int>> v;

    for (int i = 0; i < sz(r); i++) {
        v.eb(1, r[i]);
        v.eb(r[i] / 2, r[i]);
    }
    v.eb(200000, 200000);

    printf("g1 -nl=1 -nr=10 > $\n");
    printf("g3 > $\n");

    for (int i = 0; i < sz(v); i++) {
        printf("g2 -nl=%d -nr=%d -k=%d -cl=%d -cr=%d > $\n", v[i].first, v[i].second, 1, 0, 25);
        printf("g2 -nl=%d -nr=%d -k=%d -cl=%d -cr=%d > $\n", v[i].first, v[i].second, 500, 0, 25);
        printf("g2 -nl=%d -nr=%d -k=%d -cl=%d -cr=%d > $\n", v[i].first, v[i].second, 26, 0, 25);
        printf("g2 -nl=%d -nr=%d -k=%d -cl=%d -cr=%d > $\n", v[i].first, v[i].second, 26, 12, 25);
        printf("g2 -nl=%d -nr=%d -k=%d -cl=%d -cr=%d > $\n", v[i].first, v[i].second, 18, 0, 12);
    }

    return 0;
}