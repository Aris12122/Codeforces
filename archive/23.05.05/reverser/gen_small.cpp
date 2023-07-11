#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
 
struct Test{
    int n;
    vector<int> p;
 
    Test(int _n): n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 1);
        shuffle(p.begin(), p.end());
    }
 
    void print() {
        println(n);
        println(p);
    }
};
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    vector<Test> tests;
    int T = 0;
    int sum_n = 0;
    const int MAX = 200'000;

    int nl = 1, nr = 10;
 
    assert(1 <= nl && nr <= MAX);
    
    tests.emplace_back(Test(1));
    tests.emplace_back(Test(10));
    tests.emplace_back(Test(100));
    tests.emplace_back(Test(10000));
    tests.emplace_back(Test(100000));

    T = 5;
    sum_n = 1 + 10 + 100 + 10000 + 100000;


    while (T < 10'000) {
        int n = rnd.next(nl, nr);
        sum_n += n;
        if (sum_n > MAX) break;
        Test t(n);
        tests.emplace_back(t);
        T++;
    }

    reverse(tests.begin(), tests.end());
    
    println(T);
    forn(tt, T) {
        tests[tt].print();
    }
}
