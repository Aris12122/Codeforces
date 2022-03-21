#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
 
struct Test{
    int n;
    vector<int> a;
 
    Test(int _n): n(_n) {
        a.resize(n);
        forn(i, n)
            a[i] = rnd.next(-2, 2);
    }
 
    void print() {
        println(n);
        println(a);
    }
};
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    vector<Test> tests;
    int T = 0;
    int sum_n = 0;
    const int MAX = 200'000;
 
    int nl = opt<int>("nl"), nr = opt<int>("nr");
 
    assert(nl >= 1);
    assert(nr <= 200'000);

    tests.emplace_back(Test(10000));
    tests.emplace_back(Test(20000));
    tests.emplace_back(Test(100000));
    tests.emplace_back(Test(10));
    tests.emplace_back(Test(1));
    T = 5;
    
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
