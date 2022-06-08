#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
 
struct Test{
    int n;
 
    Test(int _n): n(_n) {
        
    }
 
    void print() {
        println(n);
    }
};
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    vector<Test> tests;
    int T = 0;
    int sum_n = 0;
    const int MAX = 1'000'000;

    int cur = 6;


    while (T < 10'000) {
        sum_n += ++cur;
        if (sum_n > MAX) break;
        Test t(cur);
        tests.emplace_back(t);
        T++;
    }
    
    println(T);
    forn(tt, T) {
        tests[tt].print();
    }
}
