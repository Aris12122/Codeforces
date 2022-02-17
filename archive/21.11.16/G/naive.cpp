#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()

vector<vector<int>> us;
vector<pair<int,int>> v;

int n, m;
int ans;
int cur_ans;

int id;
void solve();


void rec(int x,int y) {
    us[x][y]++;
    if (x == 0) {
        id++;
        solve();
        id--;
    } else {
        if (y > 0) {
            rec(x-1, y-1);
        }
        if (y < m-1) {
            rec(x-1, y+1);
        }
    }
    us[x][y]--;
}


void solve() {
    if (id == sz(v)) {
        ans = min(ans, cur_ans);
        return;
    }

    int x = v[id].first, y = v[id].second;
    if (us[x][y]) {
        id++;
        solve();
        id--;
    } else {
        cur_ans++;
        rec(x, y);
        cur_ans--;
    }
}

int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        
        cin >> n >> m;
        ans = n * m;
        us.resize(n,vector<int>(m,0));

        forn(i, n) {
            string s; 
            cin >> s;
            forn(j, m) {
                if (s[j] == '1')
                    v.emplace_back(i,j);
            }
        }
        reverse(v.begin(), v.end());

        if (v.empty())
            ans = 0;
        else {
            id = 0;
            cur_ans = 0;
            solve();
        }

        us.clear();
        v.clear();

        cout << ans << endl;
    }
}
