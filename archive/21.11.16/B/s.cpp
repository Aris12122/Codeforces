#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()


int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        long long a,b; cin>> a >> b;
        if(a > b) swap(a,b);
        b = min(b, 2*a);
        cout << (a + b) / 3 << endl;        
    }
}
