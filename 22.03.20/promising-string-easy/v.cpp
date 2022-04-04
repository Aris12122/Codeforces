#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
const int N = 3e3;
 
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
 
    int t = inf.readInt(1, 500, "t");
    inf.readEoln();
 
    int sum = 0;
    forn(tt, t) {
        setTestCase(tt + 1);
        int n = inf.readInt(1, N, "n");
        inf.readEoln();
 
        sum += n;
        ensuref(sum <= N, "sum_n <= 3000");
 
        pattern p("[+-]{" + to_string(n) + "}");
        inf.readLine(p, "s");
    }
 
    inf.readEof();
}
