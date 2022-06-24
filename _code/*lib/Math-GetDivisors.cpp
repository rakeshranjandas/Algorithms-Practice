#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define SHOW_DEBUG

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)
#define FORX(x, a) for (auto x: a)
#define DEBP(x)	cout << #x << "=" << x << " ";
#define _DBM_1(x) DEBP(x);
#define _DBM_2(x, ...) DEBP(x); _DBM_1(__VA_ARGS__)
#define _DBM_3(x, ...) DEBP(x); _DBM_2(__VA_ARGS__)
#define _DBM_4(x, ...) DEBP(x); _DBM_3(__VA_ARGS__)
#define _DBM_5(x, ...) DEBP(x); _DBM_4(__VA_ARGS__)
#define _DBM_6(x, ...) DEBP(x); _DBM_5(__VA_ARGS__)
#define _GET_OVERRIDE(_1, _2, _3, _4, _5, _6, NAME, ...) NAME
#ifdef SHOW_DEBUG
#define DEB(...) _GET_OVERRIDE(__VA_ARGS__, \
	_DBM_6, _DBM_5, _DBM_4, _DBM_3, _DBM_2, _DBM_1)(__VA_ARGS__) \
	cout << endl
#define DEB_VEC(v) cout<<#v<<":";for(auto x:v)cout<<" "<<x;cout<<endl
#else
#define DEB(...)
#define DEB_VEC(v)
#endif
#define SZ(x) ((int) (x).size())
#define ALL(a) (a).begin(),(a).end()
#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))
#define pb push_back
#define endl "\n"
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

typedef long long int LL;
typedef pair<int, int> PI;
typedef pair<LL, LL> PLL;
typedef pair<int, PI> PPI;

typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;

const int M = 1e9+7;
/*------------------------------------------------------------------------*/

VLL getDivisors(LL x) {
	VLL div;
	div.pb(1);
	if (x == 1)
		return div;
	div.pb(x);
	for (LL i = 2; i*i <= x; i++) {
		if (x%i != 0)
			continue;
		div.pb(i);
		if (i != x/i)
			div.pb(x/i);
	}

	return div;
}

void solve() {
	LL n;
	cin >> n;
	auto div = getDivisors(n);
	sort(ALL(div));
	string s = "";
	for (LL x: div)
		s += to_string(x) + "\n";
	cout << s << endl;
}

int main() {

	IOS

	int t = 1;
	// cin >> t;

	while (t--) {
	    solve();
	}

	return 0;
}