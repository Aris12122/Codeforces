#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back


struct Test{
    int n,m;
    int s,t;
    vector<pair<int,int>> edges;
    set<pair<int,int>> was;

 
    Test(int _n,int _m): n(_n), m(_m) {
        s = rnd.next(1, n);
        t = rnd.next(1, n-1);
        if (t >= s) t++; //s != t

        generate_tree();

        if (n * 1ll * n <= 100'000'000) {
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
        vector<int> value(n);
        iota(all(value), 1);
        forn(i, n-1) {
            int u = value[i+1], v = value[rnd.next(i+1)];
            edges.eb(u, v);
            was.insert({min(u,v), max(u,v)});
        }
    }
 
    void print() {
        println("");
        println(n, m);
        println(s, t);
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
 
    int ml = opt<int>("ml"), mr = opt<int>("mr");
    int nl = opt<int>("nl"), nr = opt<int>("nr");
 
    assert(nl >= 2 && ml >= 1);
    assert(max(mr, nr) <= N);
    assert(nl <= nr && ml <= mr && mr >= nr);
    assert(nl*1ll*(nl-1)/2 >= ml);
    assert(nr-1 <= mr);

    while (T < 10'000) {
        int n = rnd.next(nl, nr);
        int m = rnd.next(max(n-1,ml), (int)min(n*1ll*(n-1)/2,mr*1ll));
        sum_n += n;
        sum_m += m;
        if (max(sum_n, sum_m) > N) break;
        Test t(n,m);
        tests.emplace_back(t);
        T++;
    }
    
    println(T);
    forn(tt, T) {
        tests[tt].print();
    }
}
