#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
 
struct Test{
    int n,m;
    vector<string> a;
 
    Test(int _n,int _m): n(_n), m(_m) {
        a.resize(n);
        int p = rnd.next(100);
        forn(i, n) forn(j, m)
            a[i] += rnd.next(100) < p ? '0' : '1';
    }
 
    void print() {
        println("");
        println(n, m);
        forn(i, n)
            println(a[i]);
    }
};
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    vector<Test> tests;
    int T = 0;
    int sum_nm = 0;
    const int MAX = 1'000'000;

    int ml = opt<int>("ml"), mr = opt<int>("mr");
    int nl = opt<int>("nl"), nr = opt<int>("nr");

    assert(ml >= 2);
    assert(ml <= mr && nl <= nr);
    assert(max(mr, nr) <= MAX);
    
    while (T < 10'000 && sum_nm <= MAX) {
        int m = rnd.next(ml, mr);
        int cur_min = (MAX - sum_nm) / m;
        int n = rnd.next(min(cur_min, nl), min(cur_min, nr));
        if (n < 1) {
            break;
        }
        sum_nm += n*m;
        Test t(n,m);
        tests.emplace_back(t);
        T++;
    }
    
    println(T);
    forn(tt, T) {
        tests[tt].print();
    }
}