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


    T = 10;

    for (int i = 1; T < 10'000; ++i) {
        tests.emplace_back(i);
        ++T;
    }

    shuffle(begin(tests), begin(tests) + 100);


    tests.emplace_back(Test(1e5));
    tests.emplace_back(Test(1e6));
    tests.emplace_back(Test(1e8));
    tests.emplace_back(Test(1e10));
    tests.emplace_back(Test(1e12));

    tests.emplace_back(Test(rnd.next(nl, nr)));
    tests.emplace_back(Test(rnd.next(nl, nr)));
    tests.emplace_back(Test(rnd.next(nl, nr)));
    tests.emplace_back(Test(rnd.next(nl, nr)));
    tests.emplace_back(Test(rnd.next(nl, nr)));

//    shuffle(begin(tests) + 100, end(tests));


    
    println(T);
    forn(tt, T) {
        tests[tt].print();
    }
}
