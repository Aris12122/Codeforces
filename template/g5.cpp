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
            string t = to_string(i % 100);
            if (sz(t) == 1) t += '0';
            pattern p("[" + t + "]{" + to_string(m) + "}");
            phones[i] = p.next(rnd);
        }
        shuffle(phones.begin(), phones.end());
        vector<string> v;
        for (int i = 0; i < 500; i++) {
            string t = to_string(i % 100);
            if (sz(t) == 1) t = '0' + t;
            v.emplace_back(t);
        }
        shuffle(v.begin(),v.end());
        for (auto e:v) s += e;
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
    int T = 1;
    tests.emplace_back(Test(1000, 1000));
    
    println(T);
    forn(tt, T) {
        tests[tt].print();
    }
}
