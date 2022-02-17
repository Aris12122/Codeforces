#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

const int max_N = 1'000'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int t = inf.readInt(1, 10'000, "t");
    inf.readEoln();

    int sum = 0;
    forn(tt, t) {
        setTestCase(tt + 1);
        inf.readEoln();
        
        int n = inf.readInt(1, max_N, "n");
        inf.readSpace();
        int m = inf.readInt(2, max_N, "m");
        inf.readEoln();

        ensuref(n*1ll*m <= max_N, "n*m <= 1000000");
        sum += n*m;
        ensuref(sum <= max_N, "sum <= 1000000");

        pattern p("[01]{" + to_string(m) + "}");
        forn(i, n) 
            string s = inf.readString(p, "string of table");
        
    }

    inf.readEof();
}
