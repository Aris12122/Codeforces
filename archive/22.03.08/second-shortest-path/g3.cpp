#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back
 
 
struct Test{
    int n,m;
    int S,T;
    int seed;
    vector<pair<int,int>> edges;
    set<pair<int,int>> was;
 
 
    Test(int _n,int _m, int _seed=0): n(_n), m(_m), seed(_seed) {
        S = rnd.next(1, n);
        T = rnd.next(1, n-1);
        if (T >= S) T++; //s != t
 
        generate_tree();

        if (n * 1ll * n <= 10'000'000) {
            vector<pair<int,int>> candidates;
 
            for(int i = 1;i <= n; i++) for(int j = i+1;j <= n; j++) {
                if (was.count({i, j})) continue;
                
                if (rnd.next(100) > 50) {
                    candidates.emplace_back(i,j);   
                } else candidates.emplace_back(j,i);
            }
 
            
            while (sz(edges) < m) {
                assert(sz(candidates) > 0);
                int j = rnd.next(sz(candidates));
                edges.emplace_back(candidates[j]);
                swap(candidates[j], candidates.back());
                candidates.pop_back();
            }
        } else {
            while (sz(edges) < m) {
                int u = rnd.next(1, n);
                int v = rnd.next(1, n-1);
                if (v >= u) v++;
                if (was.count({u,v}) || was.count({v,u})) continue;
 
                edges.eb(u, v);
                was.insert({min(u,v), max(u,v)});
            }
        }
    }
 
    void generate_tree() {
        int t = 0;
        if (seed == 0) {
            t = rnd.next(-n, n);
        } if (seed == -1) {
            t = -n;
        } else if (seed == 1) {
            t = n;
        }

        vector<int> p(n);
        forn(i, n)
            if (i > 0)
                p[i] = rnd.wnext(i, t);
        vector<int> perm(n);
        forn(i, n)
            perm[i] = i;
        shuffle(perm.begin() + 1, perm.end());

        for (int i = 1; i < n; i++)
            if (rnd.next(2))
                edges.eb(perm[i]+1, perm[p[i]]+1);
            else
                edges.eb(perm[p[i]]+1, perm[i]+1);

        shuffle(edges.begin(), edges.end());
    }
 
    void print() {
        println("");
        println(n, m);
        println(S, T);
        forn(i, m)
            println(edges[i].first, edges[i].second);
    }
};
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    vector<Test> tests;
    int T = 0;
    int sum_n = 0, sum_m = 0;
    const int N = 200'000;
 
    int nl = opt<int>("nl"), nr = opt<int>("nr");
 
    assert(nl >= 2);
    assert(nr <= N);
    assert(nl <= nr);
 
    while (T < 10'000) {
        int n = rnd.next(nl, nr);
        int m = n - 1;
        sum_n += n;
        sum_m += m;
        if (max(sum_n, sum_m) > N) break;
        Test t(n,m, rnd.next(-1, 1));
        tests.emplace_back(t);
        T++;
    }
    
    println(T);
    forn(tt, T) {
        tests[tt].print();
    }
}
