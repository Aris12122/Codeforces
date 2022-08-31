#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)


int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int t = inf.readInt(1, 10'000, "t");
    inf.readEoln();

    pattern p("[a-z]{1,200000}");

    int sum = 0;
    forn(tt, t) {
        setTestCase(tt + 1);
        string s = inf.readLine(p, "s");

        sum += (int)s.size();
        ensuref(sum <= 200'000, "sum of string lengths expected <= 200'000");
    }

    inf.readEof();
}
