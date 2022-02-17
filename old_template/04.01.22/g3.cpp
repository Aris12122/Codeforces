#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int T = 1;
    println(T);
    forn(tt, T) {
        int n = 200'000;
        vector<int> p(n);
        forn(i, n)
            p[i] = i + 1;
        shuffle(p.begin(), p.end());
        println(n);
        println(p.begin(), p.end());
    }
}
