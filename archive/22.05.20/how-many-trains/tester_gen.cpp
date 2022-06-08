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
    vector<int> r = {20, 100, 1000, 10000, 100000};
    vector<int> l = {20, 100, 1000, 10000, 100000};

    vector<pair<int,int>> v;

    for (int i = 0; i < sz(r); i++) for (int j = 0; j < sz(l); j++) {
        v.eb(r[i], l[j]);
    }
    
    printf("g1 -nl=1 -nr=1 -ml=1 -mr=1 > $\n");
    printf("g1 -nl=1 -nr=5 -ml=1 -mr=1 > $\n");
    printf("g1 -nl=1 -nr=1 -ml=1 -mr=5 > $\n");


    for (int i = 0; i < sz(v); i++) {
        printf("g1 -nl=%d -nr=%d -ml=%d -mr=%d > $\n", v[i].first / 2, v[i].first, v[i].second, v[i].second);
        printf("g1 -nl=%d -nr=%d -ml=%d -mr=%d > $\n", v[i].first, v[i].first, v[i].second / 2, v[i].second);
        printf("g1 -nl=%d -nr=%d -ml=%d -mr=%d > $\n", 1, v[i].first, v[i].second, v[i].second);
        printf("g1 -nl=%d -nr=%d -ml=%d -mr=%d > $\n", v[i].first, v[i].first, 1, v[i].second);
        printf("g1 -nl=%d -nr=%d -ml=%d -mr=%d > $\n", v[i].first, v[i].first, v[i].second, v[i].second);
    }

    return 0;
}