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
        int n = inf.readInt(1, 200'000, "n");
        inf.readEoln();

        sum += n;
        ensuref(sum <= 200'000, "sum_n <= 200'000");

        pattern p("[+-]{" + to_string(n) + "}");
        inf.readLine(p, "s");
    }

    inf.readEof();
}
