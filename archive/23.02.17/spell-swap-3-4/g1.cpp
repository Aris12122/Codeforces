#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
 
struct Test{
    int n;
    string s, t;
 
    Test(int _n): n(_n) {
        pattern p("[a-z]{" + to_string(n) + "}");
        s = p.next(rnd);

        if (rnd.next(10) > 7) {
            t = p.next(rnd);
            return;
        }

        vector<int> perm(n);
        iota(begin(perm), end(perm), 0);
        shuffle(begin(perm), end(perm));
        t = s;
        for (int i = 0; i < n; ++i) {
            t[i] = s[perm[i]];
        }
    }
 
    void print() {
        println(n);
        println(s);
        println(t);
    }
};
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    vector<Test> tests;
    int T = 0;
    int sum_n = 0;
    const int MAX = 200'000;

    int nl = opt<int>("nl"), nr = opt<int>("nr");
 
    assert(1 <= nl && nr <= MAX);

//    tests.emplace_back(Test(100));
//    tests.emplace_back(Test(10000));
//    tests.emplace_back(Test(100000));

//    T = 3;
//    sum_n = 100 + 10000 + 100000;


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
