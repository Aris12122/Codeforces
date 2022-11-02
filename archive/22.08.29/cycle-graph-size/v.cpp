#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)


int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 1'000'000, "n");
    inf.readEoln();

    vector<int> a = inf.readInts(n, 1, n, "cycle-graph");
    inf.readEoln();
    ensuref(set<int>(a.begin(), a.end()).size() == size_t(n), "Expected a permutation");

    inf.readEof();
}
