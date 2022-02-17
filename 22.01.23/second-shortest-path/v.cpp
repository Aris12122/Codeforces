#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

vector<bool> us;
void dfs(int v,vector<vector<int>> &g) {
    us[v] = true;
    for (int to : g[v]) if (!us[to]) {
        dfs(to, g);
    }
}

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int t = inf.readInt(1, 10'000, "t");
    inf.readEoln();

    const int N = 200'000;

    int sum_n = 0, sum_m = 0;
    forn(tt, t) {
        setTestCase(tt + 1);
        inf.readEoln();
        int n = inf.readInt(2, N, "n"); inf.readSpace();
        int m = inf.readInt(1, N, "m"); inf.readEoln();

        int s = inf.readInt(1, n, "s"); inf.readSpace();
        int t = inf.readInt(1, n, "t"); inf.readEoln();

        ensuref(s != t, "Expected s != t");

        sum_n += n;
        sum_m += m;
        ensuref(sum_n <= N && sum_m <= N, "sum_n and sum_m <= 200'000");

        us.resize(n);
        forn(i, n)
            us[i] = false;
        vector<vector<int>> g(n);
        set<pair<int,int>> edg;
        forn(i, m) {
            int u = inf.readInt(1, n, "u_i") - 1; inf.readSpace();
            int v = inf.readInt(1, n, "v_i") - 1; inf.readEoln();
            ensuref(u != v, "u != v: Graph do not have self-loop");
            g[u].emplace_back(v);
            g[v].emplace_back(u);
            ensuref(!edg.count({u,v}) && !edg.count({v,u}), "Graph expected not to have equal edges");
            edg.insert({u,v});
        }

        dfs(0, g);
        forn(i, n) {
            ensuref(us[i] == true, "Graph is not connected");
        }
    }

    inf.readEof();
}
