#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

const int N = 200'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int t = inf.readInt(1, 10'000, "t");
    inf.readEoln();

    int sum = 0;
    forn(tt, t) {
        setTestCase(tt + 1);
        int n = inf.readInt(1, N, "n");
        inf.readEoln();
        vector<int> a = inf.readInts(n, -2, 2, "a");
        inf.readEoln();
        sum += n;
        ensuref(sum <= N, "sum <= 200'000");
    }

    inf.readEof();
}
