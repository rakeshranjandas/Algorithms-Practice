#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define SHOW_DEBUG

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)
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
#define ff first
#define ss second
#define uset unordered_set
#define umap unordered_map
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

// Graph is 1-based
pair<VI, VLL> ShortestPathCount(VVI &g, int n, int src = 1) {

	VI dist(n+1, INT_MAX);
	VLL ways(n+1, 0);

	queue<int> q;
	q.push(src);
	dist[src] = 0;
	ways[src] = 1;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int nxt: g[cur]) {
			if (dist[nxt] > dist[cur]+1) {
				dist[nxt] = dist[cur]+1;
				ways[nxt] = ways[cur];
				q.push(nxt);
			
			} else if (dist[nxt] == dist[cur]+1) {
				ways[nxt] += ways[cur];
				ways[nxt] %= M;
			}
		}
	}

	return {dist, ways};
}

void solve() {
	int n, m;
	cin >> n >> m;
	VVI g(n+1);
	REP(i, m) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	auto r = ShortestPathCount(g, n, 1);
	cout << r.ss[n] << endl;
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