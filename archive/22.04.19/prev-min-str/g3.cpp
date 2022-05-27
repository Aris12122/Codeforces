#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
 

int cnt = 0;
int K = 1;

struct Test{
    int n, k;
    string s;
 
    Test(int _n): n(_n) {
        assert(n == 26);
        k = K;
        K = (K) % 27 + 1;
        if (cnt & 1) {
            for (int i = 0; i < n; i++) {
                s += char(i + 'a');
            }
        } else {
            for (int i = 0; i < n; i++) {
                s += char('z' - i);
            }
        }
        
        cnt++;
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

    while (T < 10'000) {
        int n = 26;
        sum_n += n;
        if (sum_n > MAX) break;
        Test t(n);
        tests.emplace_back(t);
        T++;
    }
    
    println(T);
    forn(tt, T) {
        tests[tt].print();
    }
}
