#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
 

int K;
int cl, cr;

struct Test{
    int n, k;
    string s;
 
    Test(int _n): n(_n) {
        k = rnd.next(1, K);
        string pt = "[";
        pt += char('a' + cl);
        pt += '-';
        pt += char('a' + cr);
        pt += ']';
        pattern p(pt + "{" + to_string(n) + "}");
        s = p.next(rnd);
    }
 
    void print() {
        println(n, k);
        println(s);
    }
};
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    vector<Test> tests;
    int T = 0;
    int sum_n = 0;
    const int MAX = 200'000;

    int nl = opt<int>("nl"), nr = opt<int>("nr");
    K = 25;
    cl = 0, cr = 25;

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
    
    println(T);
    forn(tt, T) {
        tests[tt].print();
    }
}
