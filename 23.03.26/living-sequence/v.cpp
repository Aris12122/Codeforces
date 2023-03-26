#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)


int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int t = inf.readInt(1, 10'000, "t");
    inf.readEoln();

    forn(tt, t) {
        setTestCase(tt + 1);
        inf.readLong(1ll, (long long)1e12, "k");
        inf.readEoln();
    }

    inf.readEof();
}
