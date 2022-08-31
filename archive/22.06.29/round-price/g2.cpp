#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()

const int MAX = 1'000'000'000;

struct Test{
    int x;
 
    Test() {
        if (rnd.next(100) > 70) {
            x = rnd.next(1, MAX);
        } else {
            x = MAX;
        }
    }
 
    void print() {
        println(x);
    }
};
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    vector<Test> tests;
    int T = 0;
    
    
    while (T < 10'000) {
        Test t;
        tests.emplace_back(t);
        T++;
    }
    
    println(T);
    forn(tt, T) {
        tests[tt].print();
    }
}
