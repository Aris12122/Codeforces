#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int T = 10'000;
    println(T);
    forn(tt, T) {
        int n = rnd.next(1, 10);
        int m = rnd.next(1, 5);
        println("");
        
        println(n,m);
        
        pattern p("[0-9]{" + to_string(m) + "}");
        forn(i, n) {
            println(p.next(rnd));
        }
        println(p.next(rnd));
    }
}