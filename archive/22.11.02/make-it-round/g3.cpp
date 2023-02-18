#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()

int nl, nr;
int ml, mr;
 
struct Test{
    int n, m;
 
    Test() {
        n = rnd.next(nl, nr);
        m = rnd.next(ml, mr);
    }

    Test(int _n, int _m): n(_n), m(_m) {}
 
    void print() {
        println(n, m);
    }
};
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    vector<Test> tests;
    int T = 0;
    const int MAX = (int)1e9;

    nl = opt<int>("nl");
    nr = opt<int>("nr");
    ml = opt<int>("ml");
    mr = opt<int>("mr");

    while (T < 10'000) {
        T++;
        tests.emplace_back();
    }
    
    println(T);
    forn(tt, T) {
        tests[tt].print();
    }
}
