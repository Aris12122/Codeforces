#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int n;
vector<int> a;

bool readAnswer(InStream& in) {
    int p0 = in.readInt(-1, n, "p0");
    if (p0 == -1)
        return false;
    if (p0 == 0)
        in.quitf(_wa, "p0 can't be 0");
    vector<int> p(n);
    p[0] = p0;
    forn(i, n - 1)
        p[i + 1] = in.readInt(1, n, "p_i");
    if (int(set<int>(p.begin(), p.end()).size()) != n)
        in.quitf(_wa, "p is not a permutation");
    
    int l = 0, r = n - 1;
    deque<int> b;
    forn(i, n - 1)
        if (p[l] < p[r])
            b.push_front(p[l++]);
        else
            b.push_back(p[r--]);
    {
        deque<int> c(b);
        c.push_front(p[l]);
        if (vector<int>(c.begin(), c.end()) == a)
            return true;
    }
    {
        deque<int> c(b);
        c.push_back(p[l]);
        if (vector<int>(c.begin(), c.end()) == a)
            return true;
    }
    in.quitf(_wa, "p is not valid permutation");
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    int t = inf.readInt();
    int sum_n = 0;
    forn(tt, t) {
        setTestCase(tt + 1);
        n = inf.readInt();
        sum_n += n;
        a = inf.readInts(n);

        bool ja = readAnswer(ans);
        bool pa = readAnswer(ouf);
        if (ja != pa) {
            if (pa)
                quitf(_fail, "Participant has answer, but jury doesn't");
            if (ja)
                quitf(_wa, "Jury has answer, but participant doesn't");
        }
    }
    quitf(_ok, "sum_n=%d", sum_n);
}
