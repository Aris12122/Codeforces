#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

const int N = (int)1e6;


void send(int x) {
    cout << x << endl;
}

int main(int argc, char* argv[]) {
    registerInteraction(argc, argv);

    int n = inf.readInt();
    vector<int> a = inf.readInts(n);
    map<pair<int,int>, int> was;

    vector<int> pos(n+1, 0);
    for (int i = 0; i < n; i++) {
        pos[a[i]] = i;
    }

    int quer = 0;
    while (true) {
        bool is_answer = true;
        
        if (string cur = ouf.readToken("!|?"); cur == "?") {
            quer++;
            is_answer = false;
        }

        if (is_answer) {
            if (int _n = ouf.readInt(1, N); n == _n) {
                tout << quer << endl;
                quitf(_ok, "Assumed n is correct");
            } else {
                quitf(_wa, "Assumed n is incorrect");
            }
        } else {
            int a = ouf.readInt(1, N);
            int b = ouf.readInt(1, N);

            quitif(a == b, _pe, "Expected different vertexes");

            if (max(a, b) > n) {
                send(-1);
            } else {
                if (!was.count({a, b})) {
                    int dis = abs(pos[a] - pos[b]);
                    was[{a,b}] = rnd.next(2) ? dis : n - dis;
                }
                send(was[{a,b}]);
            }
        }
    }
}
