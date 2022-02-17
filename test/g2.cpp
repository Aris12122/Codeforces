#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = 100;
    for (int i = 0; i < n; i++) {
        cout << char(rnd.next(0, 25) + 'a');
    }
    cout << endl;
}
