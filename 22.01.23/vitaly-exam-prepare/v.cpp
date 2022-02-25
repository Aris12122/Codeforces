#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)


const int INF = 1'000'000'000;
const int N = 100'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int t = inf.readInt(1, 10'000, "T");
    inf.readEoln();
    int sum = 0;

    forn(tt, t) {
        setTestCase(tt + 1);
        int n = inf.readInt(1, N, "n");
        inf.readSpace();
        int m = inf.readInt(1, N, "m");
        inf.readEoln();

        sum += n * m;
        ensuref(sum <= 200'000, "sum <= 200'000");

        vector<int> a = inf.readInts(n, 1, INF, "a"); 
        inf.readEoln();
        for (int i = 1; i < n; i++) {
            ensuref(a[i] >= a[i-1], "a must be sorted");
        }
        
        forn(j, m) {
            inf.readInt(1, n, "e_i"); inf.readSpace();
            inf.readInt(1, INF, "t_i"); inf.readSpace();
            inf.readInt(1, 100, "p_i");
            inf.readEoln();
        }
    }

    inf.readEof();
}

/* 

        forn(j, m) {
            if (tt + 1 == 2657) {
                cerr << inf.readInt(1, n, "e_i") << ' '; inf.readSpace();
                cerr << inf.readInt(1, INF, "t_i") << ' '; inf.readSpace();
                cerr << inf.readInt(1, 100, "p_i") << ' ';
                inf.readEoln();
                cerr << endl;
            } else {
                inf.readInt(1, n, "e_i"); inf.readSpace();
                inf.readInt(1, INF, "t_i"); inf.readSpace();
                inf.readInt(1, 100, "p_i");
                inf.readEoln();
            }
            
        }
        if (tt + 1 == 2657) return 0;

*/