#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
 
struct Test{
    int n, m;
    vector<int> a;
    vector<int> v;
    vector<pair<int,int>> qer;
 
    Test(int _n, int _m): n(_n), m(_m) {
        a.resize(n);
        v.resize(n);
        qer.resize(m);

        forn(i, n) {
            a[i] = v[i] = rnd.next(1, 1'000'000'000);
        }

        forn(iq, m) {
            int i = rnd.next(1, n);
            int x = rnd.next(0, 1'000'000'000 - v[i-1]);
            v[i-1] += x;
            qer[iq] = make_pair(i, x);
        }
    }
 
    void print() {
        println(n, m);
        println(a);
        forn(iq, m) {
            println(qer[iq].first, qer[iq].second);
        }
    }
};
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    vector<Test> tests;
    int T = 1;
    int sum_n = 0;
    const int MAX = 200'000;

    int nl = opt<int>("nl"), nr = opt<int>("nr");
    int ml = opt<int>("ml"), mr = opt<int>("mr");

    tests.emplace_back(Test(rnd.next(nl, nr), rnd.next(ml, mr)));

    // while (T < 10'000) {
    //     int n = rnd.next(nl, nr);
    //     sum_n += n;
    //     if (sum_n > MAX) break;
    //     Test t(n);
    //     tests.emplace_back(t);
    //     T++;
    // }
    
    // println(T);
    forn(tt, T) {
        tests[tt].print();
    }
}
