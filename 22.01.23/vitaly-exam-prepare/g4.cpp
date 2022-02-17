#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()


const int INF = 1'000'000'000;
int tl, tr;


struct Test{
    int n,m;
    vector<int> a;
    vector<tuple<int,int,int>> v;
 
    Test(int _n, int _m): n(_n), m(_m) {
        a.resize(n);
        v.resize(m);
        a[0] = rnd.next(1, INF);
        forn(i, n-1) {
            a[i+1] = rnd.next(a[i], INF);
        }
        forn(j, m) {
            int e = rnd.next(1, n);
            int t = rnd.next(tl, tr);
            int p = rnd.next(1, 100);
            v[j] = make_tuple(e, t, p);
        }
    }
 
    void print() {
        println(n, m);
        println(a);
        forn(j, m) {
            auto [i,t,p] = v[j];
            println(i, t, p);
        }
    }
};

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    vector<Test> tests;
    int T = 0;
    int sum_nm = 0;
    // const int MAX = 1'000'000;
 
    int ml  = opt<int>("ml"), mr = opt<int>("mr");
    int nl  = opt<int>("nl"), nr = opt<int>("nr");
    tl      = opt<int>("tl"), tr = opt<int>("tr");
 
    assert(min(nl, ml) >= 1);
    assert(max(mr, nr) <= 100'000);
    assert(tl >= 1 && tr <= INF);
    assert(nl <= nr && ml <= mr && tl <= tr);
    // assert(mr * 1ll * nr <= MAX);
    
    while (T < 10'000) {
        int n = rnd.next(nl, nr);
        int m = rnd.next(ml, mr);
        // int n = rnd.next(nl, nr);
        sum_nm += n+m;
        if (sum_nm > 200'000) break;
        Test t(n,m);
        tests.emplace_back(t);
        T++;
    }
    
    println(T);
    forn(tt, T) {
        tests[tt].print();
    }
}