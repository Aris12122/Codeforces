#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)


int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 100'000, "n");
    inf.readSpace();
    int m = inf.readInt(1, 100'000, "m");
    inf.readEoln();

    vector<int> a = inf.readIntegers(n, 1, 1'000'000'000, "a_i");
    inf.readEoln();

    forn(q, m) {
        int i = inf.readInt(1, n, "i") - 1;
        inf.readSpace();
        int x = inf.readInt(0, 999'999'999, "x");
        a[i] += x;
        ensuref(a[i] <= 1'000'000'000, "a[i] <= 1'000'000'000");
        inf.readEoln();
    }

    inf.readEof();
}
