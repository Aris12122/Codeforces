#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include <unordered_map>
//#include"testlib.h"
#define endl '\n'
#define all(v) v.begin(),v.end()
#define allr(s) s.rbegin(),s.rend()
#define RT(s) return cout<<s,0
#define sz(s)    (int)(s.size())
//#define PI acos(-1)
#define EPS 1e-8
#define watch(x) cout << (#x)<<" = "<<x<<endl
#define mk(x, y) make_pair(x, y)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	//freopen("gcd.in", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}


void fast() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
}
struct OP {
	int e, t, p;
};
vector<OP> ops;
vi arr, show;
vector<vector<ll>> dp;
ll solve(int idx, int rem) {
	if (rem <= 0) return 0;
	if (idx == sz(arr)) return 1e15;
	ll& ret = dp[idx][rem];
	if (ret != -1) return ret;
	ret = solve(idx + 1, rem);
	auto p = ops[arr[idx]];
	ret = min(ret, p.t + solve(idx + 1, rem - p.p));
	return ret;
}
void build(int idx, int rem) {
	if (rem <= 0) return;
	if (solve(idx + 1, rem) == solve(idx, rem)) {
		build(idx + 1, rem);
		return;
	}
	auto p = ops[arr[idx]];
	show.push_back(arr[idx]);
	build(idx + 1, rem - p.p);
}
int main() {
	file();
	fast();
	int I; cin >> I;
	while (I--) {
		int n, m; 
		cin >> n >> m;
		vi a(n);
		for (auto& it : a)
			cin >> it;
		ops = vector<OP>(m);
		vector<vi> fre(n + 1);
		for (int i = 0; i < m; i++) {
			cin >> ops[i].e >> ops[i].t >> ops[i].p;
			fre[ops[i].e].push_back(i);
		}
		show.clear();
		bool ok = true;
		ll take = 0;
		for (int i = 1; i <= n; i++) {
			arr = fre[i];
			dp = vector<vector<ll>>(sz(fre[i]), vector<ll>(101, -1));
			ll mn = solve(0, 100);
			//cout << i << ' ' << mn << endl;
			if (mn + take > a[i - 1]) {
				ok = false;
				break;
			}
			build(0, 100);
		}
		if (!ok) {
			cout << "-1\n";
			continue;
		}
		cout << sz(show) << endl;
		for (auto& it : show)
			cout << it + 1 << ' ';
		cout << endl;
	}
	return 0;
}