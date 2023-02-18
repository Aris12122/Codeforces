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
        int n = inf.readInt(1, (int) 2e5, "n");
        inf.readEoln();

        sum += n;
        ensuref(sum <= (int) 2e5, "sum of n expected <= 200'000");

        pattern p("[a-z]{" + to_string(n) + "}");
        inf.readLine(p, "s");
        inf.readLine(p, "t");
    }
    inf.readEof();
}
