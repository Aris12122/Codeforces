#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define eb emplace_back
 
struct Test{
    int n;
    vector<int> a;
 
    Test(int _n): n(_n) {
        if (rnd.next(100) < 10) {
            vector<int> v;
            for (int i = 1; i <= n; i++) {
                if (i & 1) a.eb(i);
                else v.eb(i);
            }
            for (auto e : v) a.eb(e); // a = 1 3 5 .. 2 4 ..
            return;
        }
        a.resize(n);
        iota(a.begin(), a.end(), 1);
        shuffle(a.begin(), a.end()); 
    }
 
    void print() {
        println(n);
        println(a);
    }
};
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int nl = opt<int>("nl"), nr = opt<int>("nr");
    assert(1 <= nl && nl <= nr && nr <= (int)1e6);

    Test t(rnd.next(nl, nr));
    t.print();
}
