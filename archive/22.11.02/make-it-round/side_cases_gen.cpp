#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
 
struct Test{
    int n, m;

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

    tests.emplace_back(MAX, MAX);
    
    for (int i = 0; i <= 100; ++i) {
        for (int j = 0; j <= 100; ++j) {
            if (sz(tests) > 10'000) {
                break;
            }
            tests.emplace_back(MAX - i, MAX - j);
            if (j) tests.emplace_back(MAX - i, j);
            if (i) tests.emplace_back(i, MAX - j);
        }
    }

    while (sz(tests) > 10'000) {
        tests.pop_back();
    }
    T = sz(tests);

    assert(T == 10'000);
    
    println(T);
    forn(tt, T) {
        tests[tt].print();
    }
}
