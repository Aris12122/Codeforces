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
        inf.readEoln();
        int n = inf.readInt(1, 2000, "n");
        inf.readEoln();

        sum += n * n;
        ensuref(sum <= 4'000'000, "sum <= 4'000'000");

        pattern p("[0-1]{" + to_string(n) + "}");
        forn(i, n)
            inf.readLine(p, "matrix should contain only 0 or 1");
    }

    inf.readEof();
}
