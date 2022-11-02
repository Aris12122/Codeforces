#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)


int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int t = inf.readInt(1, 10'000, "t");
    inf.readEoln();

    int sum_n = 0;
    forn(tt, t) {
        setTestCase(tt + 1);
        int n = inf.readInt(1, 200'000, "n");
        inf.readEoln();

        sum_n += n;
        ensuref(sum_n <= 200'000, "sum_n expected <= 200'000");

        inf.readInts(n, 1, (int)1e9, "a");
        inf.readEoln();
    }

    inf.readEof();
}
