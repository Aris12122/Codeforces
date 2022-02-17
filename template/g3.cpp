#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
 
struct Test{
    int n,m;
    vector<string> phones;
    string s;
 
    Test(int _n,int _m): n(_n), m(_m) {
        phones.resize(n);
        pattern p("[0-9]{" + to_string(m) + "}");
        forn(i, n) {
            phones[i] = p.next(rnd);
        }
        if (rnd.next(100) < 30 || m == 1) {
            s = p.next(rnd);
        } else {
            vector<int> v;
            int sum = 0;
            while(sum < m) {
                assert(m-sum >= 2);
                int x = rnd.next(2, m - sum);
                sum += x;
                if (m - sum < 2) {
                    x += m - sum;
                    sum = m;
                }
                v.emplace_back(x);
            }
            assert(m == sum);
            forn(j, sz(v)){
                int i = rnd.next(n);
                int l = rnd.next(0, m - v[j]);
                s += phones[i].substr(l, v[j]);
            }
        }
    }
 
    void print() {
        println("");
        println(n, m);
        forn(i, n)
            println(phones[i]);
        println(s);
    }
};
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    vector<Test> tests;
    int T = 0;
    int sum_nm = 0;
    const int MAX = 1'000'000;
 
    int ml = opt<int>("ml"), mr = opt<int>("mr");
    int nl = opt<int>("nl"), nr = opt<int>("nr");
 
    assert(min(nl, ml) >= 1);
    assert(max(mr, nr) <= 200'000);
    assert(mr * 1ll * nr <= MAX);
    
    while (T < 10'000) {
        int m = rnd.next(ml, mr);
        int n = rnd.next(nl, nr);
        sum_nm += n*m;
        if (sum_nm > MAX) break;
        Test t(n,m);
        tests.emplace_back(t);
        T++;
    }
    
    println(T);
    forn(tt, T) {
        tests[tt].print();
    }
}
