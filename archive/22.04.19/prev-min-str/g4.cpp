#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
 

int K;
int cr;
vector<char> alph(26);

struct Test{
    int n, k;
    string s;
 
    Test(int _n): n(_n) {
        k = rnd.next(1, K);
        s = "";
        for (int i = 0; i < n; i++) {
            s += alph[rnd.next(cr)];
        }
    }
 
    void print() {
        println(n, k);
        println(s);
    }
};
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    vector<Test> tests;
    int T = 0;
    int sum_n = 0;
    const int MAX = 200'000;

    for (char c = 'a'; c <= 'z'; c++) {
        alph[c-'a'] = c;
    }

    K = 20;

    while (T < 10'000) {
        int n = rnd.next(1, 10);
        sum_n += n;
        if (sum_n > MAX) break;
        cr = rnd.next(1, 26);
        shuffle(all(alph));
        Test t(n);
        tests.emplace_back(t);
        T++;
    }
    
    println(T);
    forn(tt, T) {
        tests[tt].print();
    }
}
