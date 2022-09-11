#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

const long long N = (long long)1e18L;

void send(long long x) {
    cout << x << endl;
}

int main(int argc, char* argv[]) {
    registerInteraction(argc, argv);

    long long n = inf.readLong(1LL, N);
    string seedString = inf.readToken();

    long long seed = 13;
    forn(i, seedString.length())
        seed = (seed * 3343 + (seedString[i] - 'a')) % 42643801;
    rnd.setSeed(seed);

    long long mul0 = 0;
    do {
        mul0 = rnd.next(N, N + N);
    } while (gcd(mul0, n) != 1);
    __int128 mul = mul0;

    long long off = rnd.next(n);

    map<pair<long long,long long>, long long> was;

    int quer = 0;
    while (true) {
        bool is_answer = true;
        
        if (string cur = ouf.readToken("!|?"); cur == "?") {
            quer++;
            is_answer = false;
        }

        if (is_answer) {
            if (long long n_ = ouf.readLong(3LL, N); n == n_) {
                tout << quer << endl;
                quitf(_ok, "Assumed n is correct");
            } else {
                send(0);
                quitf(_wa, "Assumed n is incorrect");
            }
        } else {
            if (quer > 50) {
                send(0);
                quitf(_wa, "Too many queries (more than 50)");
            }
            
            long long a = ouf.readLong(1LL, N);
            long long b = ouf.readLong(1LL, N);

            if (a == b) {
                send(0);
                quitf(_wa, "Expected different vertexes");
            }

            if (max(a, b) > n) {
                send(-1);
            } else {
                if (!was.count({a, b})) {
                    long long posa = (long long)(((a - 1) * mul + off) % n);
                    long long posb = (long long)(((b - 1) * mul + off) % n);
                    long long dis = abs(posa - posb);
                    was[{a,b}] = rnd.next(2) ? dis : n - dis;
                }
                send(was[{a,b}]);
            }
        }
    }
}
