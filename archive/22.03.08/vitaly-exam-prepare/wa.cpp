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
		constexpr int P = 100, inf = 1e9;
		//<min time, <prev p, opt id>>
		vector<pair<int,pair<int,int>>> f(P+1, {inf,{-1,-1}});
		f[0].first = 0;
		//vector fs(1, f);
		for(int k : g[h]) {
			auto [_, t, p] = opt[k];
			for(int x = P-1; x>=0; --x) {
				int y = min(P, x + p);
				if(umin(f[y].first, f[x].first + t)) {
					f[y].second = {x, k};
				}
			}
			//fs.push_back(f);
		}
		
		int rem = a[h] - pref;
		if(rem < f[P].first) {
			cout << -1 << endl;
			return ;
		}
		pref += f[P].first;
		
		int x = P;
		while(x > 0) {
			auto [y, k] = f[x].second;
			assert(k!=-1);
			cert.push_back(k + 1);
			x = y;
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
