#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
 
int t;
 
struct Test{
    int n;
    string s;
 
    Test(int _n): n(_n) {
        for (int i = 0; i < n; i++) {
            if (rnd.next(0, 100) <= t) {
                s += '+';
            } else {
                s += '-';
            }
        }
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
    const int MAX = 200'000;
    
    t = opt<int>("t");
    assert(0 <= t && t < 100);

    int tt = 0;
    while (T < 10'000) {
        int n = ++tt;
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
