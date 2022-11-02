#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)


int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int t = inf.readInt(1, 10'000, "t");
    inf.readEoln();


    pattern p("X{0,49}[MLS]");

    forn(tt, t) {
        setTestCase(tt + 1);
        string s = inf.readToken(p, "a"); inf.readSpace();
        ensuref(s.back() != 'M' || s.length() == 1, "M cannot have X at prefix");
        
        s = inf.readToken(p, "b"); inf.readEoln();
        ensuref(s.back() != 'M' || s.length() == 1, "M cannot have X at prefix");
    }

    inf.readEof();
}
