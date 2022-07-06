#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()

struct Test{
    int x;
 
    Test(int kl, int kr) {
        x = rnd.next(kl, kr);
    }
 
    void print() {
        println(x);
    }
};
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    vector<Test> tests;
    int T = 0;
    const int MAX = 1'000'000'000;

    int nl = opt<int>("nl"), nr = opt<int>("nr");
 
    assert(1 <= nl && nr <= MAX);
    
    while (T < 10'000) {
        Test t(nl, nr);
        tests.emplace_back(t);
        T++;
    }
    
    println(T);
    forn(tt, T) {
        tests[tt].print();
    }
}
