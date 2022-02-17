#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()

int n, m;
vector<int> a;
vector<tuple<int,int,int>> v;

bool readAnswer(InStream& in) {
    int k = in.readInt(-1, m, "k");
    if (k == -1)
        return false;
    if (k == 0)
        in.quitf(_wa, "k can't be 0");
    
    vector<int> curp(n+1, 0);
    set<int> st;
    int curt = 0, curi = 1;

    forn(q, k) {
        int j = in.readInt(1, m, "option index");
        in.quitif(st.count(j), _wa, "All indeces expected different");
        st.insert(j);
        
        auto [e,t,p] = v[j];
        curt += t;
        while (curi <= n && a[curi] < curt) {
            in.quitif(curp[curi] < 100, _wa, "Vitaly has to prepare for each exam on time");
            curi++;
        }
        curp[e] += p;
    }
    while (curi <= n) {
        in.quitif(curp[curi] < 100, _wa, "Vitaly has to prepare for all exams");
        curi++;
    }
    return true;
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    int t = inf.readInt();
    int sum_nm = 0;
    forn(tt, t) {
        setTestCase(tt + 1);
        n = inf.readInt();
        m = inf.readInt();
        sum_nm += n * m;

        a.resize(n+1);
        forn(i, n) {
            a[i+1] = inf.readInt();
        }
        v.resize(m+1);
        forn(i, m) {
            int e,t,p;
            e = inf.readInt();
            t = inf.readInt();
            p = inf.readInt();
            v[i+1] = make_tuple(e, t, p);
        }

        bool ja = readAnswer(ans);
        bool pa = readAnswer(ouf);
        
        if (ja != pa) {
            if (pa)
                quitf(_fail, "Participant has answer, but jury doesn't");
            if (ja)
                quitf(_wa, "Jury has answer, but participant doesn't");
        }
    }
    quitf(_ok, "sum_nm=%d", sum_nm);
}
