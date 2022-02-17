#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()


int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        long long a,b; cin >> a >> b;
        int ans = 0;
        for(int x=0;;x++) {
            if(x > a || 2*x > b) break;
            for(int y=0;;y++) {
                if(x + 2*y > a || 2*x + y > b) break;
                ans = max(ans, x + y);
            }
        }
        cout << ans << endl;
    }
}
