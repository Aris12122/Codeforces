#include<bits/stdc++.h>
using namespace std;
template<class T,class S=T>inline bool umin(T&m,S&&x){return x<m?m=x,1:0;}
template<class T,class S=T>inline bool umax(T&m,S&&x){return m<x?m=x,1:0;}
auto operator<<(ostream&o,auto&&v)->enable_if_t<!is_constructible_v<string,decltype(v)>,decltype(o<<*end(v))>{int f=0,u=&o==&cerr&&o<<"[";for(auto&&x:v)(f++?o<<", "+!u:o)<<x;return u?o<<"]":o;}
auto operator<<(ostream&o,auto&&t)->decltype(o<<get<0>(t)){o<<"<";apply([&o](auto&...x){int f=0;(((f++?o<<", ":o)<<x),...);},t);return o<<">";}
#ifdef BIZON
	#define rr(...) [](auto&&...x){ cerr << boolalpha << "\e[1;38;5;68m" << #__VA_ARGS__ << " "; int _=0; ((cerr<<"\e[0;38;5;61m"<<",="[!_++]<<"\e[0m "<<x),...)<<endl; }(__VA_ARGS__);
#else
	#define rr(...) 0;
	#define endl '\n'
#endif
#define bb(c) begin(c), end(c)
#define ff(T, name, ...) function<T(__VA_ARGS__)> name = [&](__VA_ARGS__)->T
#define jj(...) __VA_ARGS__; [](auto&...x){(cin>>...>>x);}(__VA_ARGS__);
#define ii(...) int jj(__VA_ARGS__)
using ll = long long;


void run_case(const size_t ____test) { // rr(____test)
	ii(n, m)
	vector<int> a(n);
	for(auto &_ : a) cin>>_;
	
	vector<tuple<int,int,int>> opt;
	vector<vector<int>> g(n);
	for(int k=0; k<m; ++k) {
		ii(e, t, p)
		--e;
		opt.emplace_back(e, t, p);
		g[e].push_back(k);
	}
	
	int pref = 0;
	vector<int> cert;
	for(int h=0; h<n; ++h) {
		constexpr int P = 100, inf = 2e9; //wrong inf
		vector<
			//<min time, <prev p, opt id>>
			vector<pair<int,pair<int,int>>>
		> dp;
		dp.emplace_back(P+1);
		dp[0][0].first = 0;
		for(int x=1; x<=P; ++x) dp[0][x] = {inf, {-1,-1}};
		for(int k : g[h]) {
			auto &f = dp.emplace_back(dp.back());
			for(int x=0; x<=P; ++x) f[x].second.first = x;
			
			auto [_, t, p] = opt[k];
			for(int x = P-1; x>=0; --x) {
				int y = min(P, x + p);
				if(umin(f[y].first, f[x].first + t)) {
					f[y].second = {x, k};
				}
			}
		}
		
		int rem = a[h] - pref;
		int mintime = dp.back()[P].first;
		if(rem < mintime) {
			cout << -1 << endl;
			return ;
		}
		pref += mintime;
		
		int x = P;
		for(int i = size(g[h]); i; --i) {
			auto [y, k] = dp[i][x].second;
			if(x != y) {
				cert.push_back(k+1);
				x = y;
			}
			
		}
	}
	
	cout << size(cert) << endl;
	cout << cert << endl;
}

int main() {
	// if(auto f="in.txt"; fopen(f,"r") && freopen(f,"r",stdin));
	cin.tie(0)->sync_with_stdio(0);
	
	size_t tn = 1; cin>>tn;
	for(size_t t=1; t<=tn; ++t) run_case(t);
	
	return 0;
}