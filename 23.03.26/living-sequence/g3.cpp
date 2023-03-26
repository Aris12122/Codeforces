#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()

using ll = long long;

struct Test{
    ll k;
 
    Test(ll _n): k(_n) {
    }
 
    void print() {
        println(k);
    }
};
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    vector<Test> tests;
    int T = 0;
    const ll MAX = (ll)1e12;

    ll nl = opt<ll>("nl"), nr = opt<ll>("nr");
 
    assert(1 <= nl && nr <= MAX);

    while (T < 10'000) {
        tests.emplace_back(min(max(1ll, rnd.next(nl, nr)), MAX));
        ++T;
    }

    println(T);
    forn(tt, T) {
        tests[tt].print();
    }
}
