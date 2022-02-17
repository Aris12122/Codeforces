#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
struct Test{
    int n,m;
    vector<string> a;
 
    Test(int _n,int _m): n(_n), m(_m) {
        a.resize(n);
        int p = rnd.next(100);
        forn(i, n) forn(j, m)
            a[i] += char('0' + int(rnd.next(100) < p));
    }
 
    void print() {
        forn(i, n)
            println(a[i]);
    }
};
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    int T = 10'000;
    println(T);
    forn(tt, T) {
        int n = rnd.next(1, 5), m = rnd.next(2, 5);
        Test t(n,m);
        println("");
        println(n, m);
        t.print();
    }
}