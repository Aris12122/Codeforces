#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

bool dfs(int v, int p, vector<vector<int>> &g, vector<bool> &used) {
    used[v] = true;
    for(int u: g[v]){
        if(u != p){
            if(used[u] || !dfs(u, v, g, used)) return false;
        }
    }
    return true;
}

void tree(int n) {
    int k = inf.readInt(1, n - 1, "k");
    inf.readEoln();
    
    vector<int> x = inf.readInts(k, 2, n, "x");
    inf.readEoln();
    sort(x.begin(), x.end());
    for(int i = 1; i < k; ++i){
        ensuref(x[i] != x[i - 1], "friends stay in same room %d %d", x[i], x[i - 1]);
    }
    
    set<pair<int, int>> edges;
    vector<vector<int>> g(n);
    vector<bool> used(n);
    for (int i = 1; i < n; ++i) {
        int u = inf.readInt(1, n, "u");
        inf.readSpace();
        int v = inf.readInt(1, n, "v");
        inf.readEoln();
        ensuref(u != v, "u = v = %d", u);
        if (u > v) swap(u, v);
        ensuref(edges.count({u, v}) == 0, "edge %d-%d written twice", u, v);
        edges.insert({u, v});
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    
    ensuref(dfs(0, -1, g, used), "there is cycle in graph");
    ensuref(count(used.begin(), used.end(), true) == n, "expected n visited vertices");
}

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int t = inf.readInt(1, 10'000, "t");
    inf.readEoln();
    int sum = 0;
    for (int i = 0; i < t; ++i) {
        setTestCase(i + 1);
        inf.readEoln();
        int n = inf.readInt(2, 200'000, "n");
        inf.readSpace();
        sum += n;
        ensuref(sum <= 200'000, "sum <= 200000");
        tree(n);
    }
    inf.readEof();
}
