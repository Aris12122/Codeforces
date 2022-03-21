#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int n;
vector<int> a;

int readAnswer(InStream& in) {
    int p = in.readInt(0, n, "p");
    int s = in.readInt(0, n, "s");
    in.quitif(p + s > n, _wa, "sum p + s expected less than n");
    int cnt = 0;
    bool neg = false;

    for (int i = p; i < n - s; i++) {
        if (abs(a[i]) == 2) cnt++;
        neg ^= a[i] < 0;
        if (a[i] == 0) return 0;
    }
    if (neg) cnt = -cnt;
    return cnt;
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    int t = inf.readInt();
    int sum_n = 0;
    forn(tt, t) {
        setTestCase(tt + 1);
        n = inf.readInt();
        a = inf.readInts(n);
        
        sum_n += n;

        int ja = readAnswer(ans);
        int pa = readAnswer(ouf);
        
        if (ja != pa) {
            if (pa > ja)
                quitf(_fail, "Participant has better answer than jury");
            if (pa < ja)
                quitf(_wa, "The product of numbers on the resulting array is not the maximum");
        }
    }
    quitf(_ok, "sum_n=%d", sum_n);
}
