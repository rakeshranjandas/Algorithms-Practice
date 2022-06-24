#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)
#define FORX(x, a) for (auto x: a)
#define DEB(x)	cout << #x << " " << x << endl;
#define DEB_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()
#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))
#define pb push_back

typedef long long int LL;
typedef pair<int, int> PI;
typedef pair<LL, LL> PLL;
typedef pair<int, PI> PPI;

typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<vector<int>> VVI;

void dfs(VVI &g, int cur, int par, VI &disc, VI &low, VVI &b, int &cnt) {
	if (disc[cur] != INT_MAX)
		return;

	disc[cur] = low[cur] = cnt++;

	for (auto next: g[cur]) {

		// Skip if parent
		if (next == par)
			continue;

		// If already visited, update low[cur]
		if (disc[next] != INT_MAX) {
			low[cur] = min(low[cur], disc[next]);
			continue;
		}

		// Dfs next
		dfs(g, next, cur, disc, low, b, cnt);
		low[cur] = min(low[cur], low[next]);

		// Bridge if lowest node reachable from next
		// is higher than current's discovery id
		if (disc[cur] < low[next])
			b.pb({cur, next});
	}
}

VVI findBridges(VVI &g) {
	VVI b;
	int n = g.size();
	VI disc(n, INT_MAX), low(n, INT_MAX);
	int cnt = 0;

	REP(i, n)
		dfs(g, i, -1, disc, low, b, cnt);

	return b;
}

int main() {

	IOS

	VVI g(4);
	g[0].pb(1);
	g[1].pb(0);

	g[1].pb(2);
	g[2].pb(1);

	g[2].pb(0);
	g[0].pb(2);

	g[1].pb(3);
	g[3].pb(1);

	auto bridges = findBridges(g);
	cout << "Bridges: " << endl;
	FORX(be, bridges)
		cout << be[0] << " " << be[1] << endl;


	return 0;
}