#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
 
int M;

int get_int() {
    int rd = rnd.next(1, 10000);
    if (rd == 1) return 1;
    else if (rd == 10000) return M;
    return rnd.next(1, M);
}

struct Test{
    int n;
    vector<int> a;
 
    Test(int _n): n(_n) {
        a.resize(n);
        if (rnd.next(4) == 0 || n == 1) { // random
            forn(i, n) {
                a[i] = get_int();
            }
        } else { //YES
            vector<vector<int>> blocks;
            int m = 0;
            while (n != m) {
                int k = n - m > 4 ? rnd.next(1, n - m - 3) : n - m - 1; // n - m = 1
                m += k + 1;
                vector<int> cur;
                forn(i, k) cur.emplace_back(get_int());
                blocks.emplace_back(cur);
            }

            shuffle(begin(blocks), end(blocks));

            int i = 0;
            for (auto block : blocks) {
                assert(!block.empty());
                bool first = rnd.next(2);
                if (first) a[i++] = sz(block);
                for (auto e : block) a[i++] = e;
                if (!first) a[i++] = sz(block);
            }
        }
    }
 
    void print() {
        println(n);
        println(a);
    }
};
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    vector<Test> tests;
    int T = 0;
    int sum_n = 0;
    const int MAX = 200'000;

    int nl = opt<int>("nl"), nr = opt<int>("nr");
    M = opt<int>("M");

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

    reverse(begin(tests), end(tests));
    
    println(T);
    forn(tt, T) {
        tests[tt].print();
    }
}
