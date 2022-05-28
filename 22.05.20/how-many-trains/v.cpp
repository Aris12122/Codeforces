#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)


int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int t = inf.readInt(1, 10'000, "t");
    inf.readEoln();

    int sum_n = 0, sum_m = 0;
    forn(tt, t) {
        setTestCase(tt + 1);
        inf.readEoln();
        int n = inf.readInt(1, 100'000, "n");
        inf.readSpace();
        int m = inf.readInt(1, 100'000, "m");
        inf.readEoln();

        sum_n += n, sum_m += m;

        ensuref(sum_n <= 100'000, "sum_n <= 100'000");
        ensuref(sum_m <= 100'000, "sum_m <= 100'000");

        vector<int> a = inf.readIntegers(n, 0, 1'000'000'000, "a_i");
        inf.readEoln();

        forn(q, m) {
            int i = inf.readInt(1, n, "i") - 1;
            inf.readSpace();
            int x = inf.readInt(0, 1'000'000'000, "x");
            a[i] -= x;
            ensuref(a[i] >= 0, "a[i] >= 0");
            inf.readEoln();
        }
    }


    inf.readEof();
}
