#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int T = 10'000;
    println(T);
    forn(tt, T) {
        int n = rnd.next(1, 4);
        int m = rnd.next(1, 7);
        println("");
        
        println(n,m);
        
        string p("[0-9]{" + to_string(m) + "}");
        forn(i, n) {
            println(rnd.next(p));
        }
        println(rnd.next(p));
    }
}
