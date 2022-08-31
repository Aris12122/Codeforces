#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()

int K;

struct Test{
    int n;
    vector<int> a, b;
 
    Test(int _n): n(_n) {
        a.resize(n);
        b.resize(n);
        forn(i, n) {
            b[i] = rnd.next(1, K);
        }
        sort(all(b));

        if (rnd.next(100) > 75) {
            forn(i, n) {
                a[i] = rnd.next(1, K);
            }
        } else {
            forn(i, n) {
                int x = b[i];
                forn(cnt, 30) {
                    if (rnd.next(100) > 50 && x != 1) {
                        x /= 2;
                    } else if (x * 2 > K) {
                        if (x == 1) break;
                        x /= 2;
                    } else {
                        x *= 2;
                    }
                }
                a[i] = x;
            }
        }
        
        sort(all(a));
    }
 
    void print() {
        println(n);
        forn(i, n) cout << a[i] << (i == n-1 ? '\n' : ' ');
        forn(i, n) cout << b[i] << (i == n-1 ? '\n' : ' ');
    }
};
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    vector<Test> tests;
    int T = 0;
    int sum_n = 0;
    const int MAX = 200'000;

    int nl = opt<int>("nl"), nr = opt<int>("nr");
    K = opt<int>("K");

    assert(1 <= nl && nr <= MAX);
    
    // tests.emplace_back(Test(1));
    // tests.emplace_back(Test(10));
    // tests.emplace_back(Test(100));
    // tests.emplace_back(Test(10000));
    // tests.emplace_back(Test(100000));

    // T = 5;
    // sum_n = 1 + 10 + 100 + 10000 + 100000;


    while (T < 10'000) {
        int n = rnd.next(nl, nr);
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
