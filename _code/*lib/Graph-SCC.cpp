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
#define DEB_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
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

class SCC {
	int n;
	vector<vector<int>> g, gr;
	vector<int> conn, trv;

	void process() {
		n = g.size();

		doDfs1();
		revGraph();
		doDfs2();
	}

	void doDfs1() {
		vector<int> visited(n, false);
		for (int i = 0; i < n; i++)
			dfs1(i, visited);

		reverse(trv.begin(), trv.end());
	}

	void dfs1(int cur, vector<int> &visited) {
		if (visited[cur])
			return;
		visited[cur] = true;

		for (auto nxt: g[cur])
			dfs1(nxt, visited);

		trv.push_back(cur);
	}

	void revGraph() {
		gr.resize(n);
		for (int i = 0; i < n; i++) {
			for (auto nxt: g[i])
				gr[nxt].push_back(i);
		}
	}

	void dfs2(int cur, int scci) {
		if (conn[cur] != -1)
			return;

		conn[cur] = scci;
		for (auto nxt: gr[cur])
			dfs2(nxt, scci);
	}

	void doDfs2() {
		conn.resize(n, -1);
		int scci = 0;
		for (auto t: trv)
			dfs2(t, ++scci);
	}

	public:
	SCC(VVI &gi) {
		g = gi;
		process();
	}

	vector<int> getConn() {
		return conn;
	}
};

void solve() {
	int n, m;
	VVI g;
	VI cost, conn;
	cin >> n;
	cost.resize(n);
	REP(i, n)
		cin >> cost[i];

	g.resize(n);
	cin >> m;
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
	}

	SCC scc = SCC(g);
}

int main() {

	IOS

	// int t;
	// cin >> t;

	// while (t--) {
	    solve();
	// }

	return 0;
}