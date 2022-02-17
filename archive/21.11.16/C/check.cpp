#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int n, r;
vector<int> b, p;

const int MX = 1'000'000'000;

vector<vector<pair<int,int>>> g;
vector<long long> d;

void dfs(int v) {
    for (auto [to, w] : g[v]) {
        d[to] = d[v] + w;
        dfs(to);
    }
}

bool readAnswer(InStream& in) {
    int w0 = in.readInt(-1, MX, "w0");
    if (w0 == -1)
        return false;
    vector<int> w(n);
    w[0] = w0;

    forn(i, n-1) 
        w[i+1] = in.readInt(0, MX, "w_i");
    if (w[r] != 0)
        in.quitf(_wa, "w_i must be 0 for root");
    
    g.clear();
    g.resize(n);

    forn(i, n) { 
        if (w[i] == 0 && r != i) 
            in.quitf(_wa, "w_i = 0 only for root");
        if (i != r)
            g[b[i] - 1].emplace_back(i, w[i]);
    }
    
    d.clear();
    d.resize(n, 0);
    d[r] = 0;
    dfs(r);

    forn(i, n-1) 
        if (d[p[i]-1] >= d[p[i+1]-1]) 
            in.quitf(_wa, "d[p[i]] must be < d[p[i+1]]");
    return true;
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    int t = inf.readInt();
    int sum_n = 0;
    forn(tt, t) {
        setTestCase(tt + 1);
        n = inf.readInt();
        sum_n += n;
        b = inf.readInts(n);
        p = inf.readInts(n);

        forn(i, n) 
            if (b[i]-1 == i) r = i;

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
