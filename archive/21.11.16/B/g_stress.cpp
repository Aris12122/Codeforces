#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

const int N = 1'000'000'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int T = 10'000;
    println(T);
    forn(tt, T) {
        int a = rnd.next(0, opt<int>("m"));
        int b = rnd.next(0, opt<int>("m"));
        println(a, b);
    }
}
