#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int n;

int readAnswer(InStream& in) {
    int b = in.readInt(1, n, "h_2");
    int a = in.readInt(1, n, "h_1");
    int c = in.readInt(1, n, "h_3");
    in.quitif(a <= b, _wa, "platform for 1-st place must be higher than platform for 2-nd place");
    in.quitif(b <= c, _wa, "platform for 2-nd place must be higher than platform for 3-rd place");
    in.quitif(a + b + c != n, _wa, "The sum of platform heights must be equal to n");
    return a;
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    int t = inf.readInt();
    int sum_n = 0;
    forn(tt, t) {
        setTestCase(tt + 1);
        n = inf.readInt();
        inf.readEoln();
        sum_n += n;

        int ja = readAnswer(ans);
        int pa = readAnswer(ouf);
        
        if (ja != pa) {
            if (pa < ja)
                quitf(_fail, "Participant has answer, but jury doesn't");
            if (ja < pa)
                quitf(_wa, "The platform height for 1-st place is not minimal");
        }
    }
    quitf(_ok, "sum_n=%d", sum_n);
}
