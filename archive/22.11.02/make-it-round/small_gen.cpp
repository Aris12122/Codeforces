#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int T = 0;
    
    println(10'000);
    
    for (int n = 1; n <= 100; ++n) {
        for (int m = 1; m <= 100; ++m) {
            T++;
            println(n, m);
        }
    }

    assert(T == 10'000);
}
