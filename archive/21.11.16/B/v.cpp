#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

const int N = 1'000'000'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int t = inf.readInt(1, 10'000, "t");
    inf.readEoln();

    forn(tt, t) {
        setTestCase(tt + 1);
        inf.readInt(0, N, "a"); 
        inf.readSpace();
        inf.readInt(0, N, "b");
        inf.readEoln();
    }
    inf.readEof();
}
