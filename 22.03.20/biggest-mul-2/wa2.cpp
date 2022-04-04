#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0, l = 0, r = n;
    int cnt = 0, ot = 0, ii = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            cnt = 0, ot = 0, ii = i + 1;
            continue;
        }
        if (a[i] < 0) {
            ot ^= 1;
        }
        if (abs(a[i]) == 2) {
            cnt++;
        }
        if (!ot && cnt > ans) {
            l = ii, r = n - i - 1;
            ans = cnt;
        }
    }

    cnt = 0, ot = 0, ii = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 0) {
            cnt = 0, ot = 0, ii = i - 1;
            continue;
        }
        if (a[i] < 0) {
            ot ^= 1;
        }
        if (abs(a[i]) == 2) {
            cnt++;
        }
        if (!ot && cnt > ans) {
            l = i, r = n - ii - 1;
            ans = cnt;
        }
    }
    cout << l << ' ' << r << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    for (; _; --_) {
        solve();
    }
    return 0;
}