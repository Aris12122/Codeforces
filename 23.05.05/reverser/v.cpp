#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define all(v) v.begin(),v.end()


int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int t = inf.readInt(1, 10'000, "t");
    inf.readEoln();

    int sum = 0;
    forn(tt, t) {
        setTestCase(tt + 1);
        int n = inf.readInt(1, (int)2e5, "n");
        inf.readEoln();
        sum += n;

        ensuref(sum <= (int)2e5, "Sum of n expected less or equal 200'000");

        vector<int> p = inf.readInts(n, 1, n, "p");
        inf.readEoln();
        ensuref(int(set<int>(all(p)).size()) == n, "expected permutation");
    }

    inf.readEof();
}
