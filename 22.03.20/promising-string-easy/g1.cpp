#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
 
struct Test{
    int n;
    string s;
 
    Test(int _n): n(_n) {
        pattern p("[+-]{" + to_string(n) + "}");
        s = p.next(rnd);
    }
 
    void print() {
        println(n);
        println(s);
    }
};
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    vector<Test> tests;
    int T = 0;
    int sum_n = 0;
    const int MAX = 2000;
 
    int nl = opt<int>("nl"), nr = opt<int>("nr");
 
    assert(nl >= 1);
    assert(nr <= MAX);

    tests.emplace_back(Test(1));
    tests.emplace_back(Test(100));
    tests.emplace_back(Test(1000));
    tests.emplace_back(Test(10));
    tests.emplace_back(Test(500));
    T = 5;
    sum_n = 1000 + 500 + 100 + 10 + 1;
    
    while (T < 1000) {
        int n = rnd.next(nl, nr);
        sum_n += n;
        if (sum_n > MAX) break;
        Test t(n);
        tests.emplace_back(t);
        T++;
    }

    reverse(tests.begin(),tests.end());
    
    println(T);
    forn(tt, T) {
        tests[tt].print();
    }
}
