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
        ensuref(sum_n <= 200'000, "sum_n <= 200'000");

        vector<int> a = inf.readInts(n, 1, 1'000'000'000, "a");
        forn(i, n-1) {
            ensuref(a[i] <= a[i+1], "Expected a[i] <= a[i+1]");
        }
        inf.readEoln();

        vector<int> b = inf.readInts(n, 1, 1'000'000'000, "b");
        forn(i, n-1) {
            ensuref(b[i] <= b[i+1], "Expected b[i] <= b[i+1]");
        }
        inf.readEoln();

    }

    inf.readEof();
}
