#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int T = 10'000;
    println(T);
    forn(tt, T) {
        int a = rnd.next(opt<int>("mn"), opt<int>("mx"));
        int b = rnd.next(opt<int>("mn"), opt<int>("mx"));
        println(a, b);
    }
}
