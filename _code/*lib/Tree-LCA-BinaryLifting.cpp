#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define SHOW_DEBUG

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)
#define DEBP(x)	cerr << #x << "=" << x << " ";
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
	cerr << endl
#define DEB_VEC(v) cerr<<#v<<":";for(auto x:v)cerr<<" "<<x;cerr<<endl
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

const int MAX_BIT = 20;

int n, q;
VVI g;

struct BinaryLiftingLCA {
	int n;
	VVI p;
	VI depth;

	public:

	BinaryLiftingLCA(VVI &g, int n) {
		this->n = n;
		
		p.resize(MAX_BIT, VI(n+1));
		depth.resize(n+1);

		dfs(1, 0);
		initTable();
	}

	void dfs(int cur, int par) {
		p[0][cur] = par;
		depth[cur] = cur == 1 ? 0 : (1+depth[par]);

		for (int nxt: g[cur]) {
			if (nxt == par)
				continue;
			dfs(nxt, cur);
		}
	}

	void initTable() {
		FOR(bit, 1, MAX_BIT)
			FOR(i, 1, n+1)
				p[bit][i] = p[bit-1][p[bit-1][i]];
	}

	int getLCA(int x, int y) {
		int levx = depth[x];
		int levy = depth[y];

		if (levx < levy) {
			swap(x, y);
			swap(levx, levy);
		}

		x = kthAncestor(x, levx-levy);

		if (x == y)
			return x;

		FORR(bit, 0, MAX_BIT) {
			int px = p[bit][x];
			int py = p[bit][y];

			if (px == py)
				continue;

			x = px;
			y = py;
		}

		return p[0][x];
	}

	int kthAncestor(int x, int k) {
		REP(bit, MAX_BIT)
			if (k&(1<<bit))
				x = p[bit][x];

		return x;
	}
};

void solve() {
	cin >> n >> q;
	g.resize(n+1);
	FOR(i, 2, n+1) {
		int par;
		cin >> par;
		g[par].pb(i);
		g[i].pb(par);
	}

	auto binaryLiftLCA = BinaryLiftingLCA(g, n);

	while (q--) {
		int a, b;
		cin >> a >> b;
		cout << binaryLiftLCA.getLCA(a, b) << endl;
	}
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