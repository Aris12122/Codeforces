#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

vector<vector<int>> g;
vector<bool> us;

void dfs(int v) {
    ensuref(!us[v], "Tree can't contain a cycle");
    us[v] = true;
    for(int to : g[v]) {
        dfs(to);
    }
}


void is_tree(int n, vector<int>& b) {
    g.clear();
    us.clear();
    g.resize(n);
    us.resize(n, false);

    int r = -1;
    forn(i, n) {
        if (i == --b[i]) {
            ensuref(r == -1, "Tree must contain only 1 root");
            r = i;
        } else 
            g[b[i]].emplace_back(i);
    }
    ensuref(r != -1, "Tree must contain a root");
    dfs(r);
    ensuref(count(us.begin(), us.end(), true) == n, "Dfs must visit all vertices");
}

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int t = inf.readInt(1, 10'000, "t");
    inf.readEoln();

    int sumn = 0;
    forn(tt, t) {
        setTestCase(tt + 1);

        int n = inf.readInt(1, 200'000, "n");
        inf.readEoln();

        sumn += n;
        ensuref(sumn <= 200'000, "sum <= 200000");
        
        vector<int> b = inf.readInts(n, 1, n, "a");
        inf.readEoln();
        vector<int> p = inf.readInts(n, 1, n, "p");
        inf.readEoln();
        ensuref(int(set<int>(p.begin(), p.end()).size()) == n, "p must be a permutation");

        is_tree(n, b);
    }

    inf.readEof();
}
