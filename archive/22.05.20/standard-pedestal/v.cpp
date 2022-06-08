#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)


int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int t = inf.readInt(1, 10'000, "t");
    inf.readEoln();

    int sum = 0;
    forn(tt, t) {
        setTestCase(tt + 1);
        int n = inf.readInt(6, 100'000, "n");
        inf.readEoln();

        sum += n;
        ensuref(sum <= 1'000'000, "sum <= 1'000'000");
    }

    inf.readEof();
}
