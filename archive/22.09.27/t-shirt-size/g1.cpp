#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
 
struct Test{
    string a, b;

    Test(int _n, char c1) {
        for (int i = 0; i < _n; i++) a += 'X', b += 'X';
        a += c1;
        b += c1;
    }
 
    Test(int _n, char c1, int _m, char c2) {
        for (int i = 0; i < _n; i++) a += 'X';
        for (int i = 0; i < _m; i++) b += 'X';
        a += c1;
        b += c2;
    }
 
    void print() {
        println(a, b);
    }
};
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    vector<Test> tests;

    int T = 1;
    tests.emplace_back(0, 'M', 0, 'M');

    for (int i = 0; i < 50; i++) {
        tests.emplace_back(i, 'L');
        T++;
    }
    for (int i = 0; i < 49; i++) {
        tests.emplace_back(i, 'S');
        T++;
    }
    T = 100;

    while (T < 10'000) {
        int n = rnd.next(50);
        int m = rnd.next(50);
        if (rnd.next(2)) {
            tests.emplace_back(n, 'S', m, 'L');
        } else {
            tests.emplace_back(n, 'L', m, 'S');
        }
        tests.emplace_back(n, 'S', 0, 'M');
        tests.emplace_back(0, 'M', m, 'L');
        T += 3;
    }
    
    println(T);
    forn(tt, T) {
        tests[tt].print();
    }
}
