#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)
#define DEB(x)	cout << #x << " " << x << endl;
#define DEB_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()
#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

typedef long long int LL;
typedef pair<int, int> PI;
typedef pair<LL, LL> PLL;
typedef pair<int, PI> PPI;

typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<vector<int>> VVI;

class UF {
	private:
	vector<int> par, sz;

	public:
	UF(int n) {
		par.resize(n);
		REP(i, n)
			par[i] = i;
		sz.resize(n, 1);
	}

	int findPar(int x) {
		if (x == par[x])
			return x;
		return findPar(par[x]);
	}

	int isConnected(int a, int b) {
		return findPar(a) == findPar(b);
	}

	void connect(int a, int b) {
		a = findPar(a);
		b = findPar(b);

		if (!isConnected(a, b)) {
			if (sz[a] < sz[b])
				swap(a, b);

			par[b] = a;
			sz[a] += sz[b];
		}
	}
};

int main() {

	IOS

	UF uf = UF(10);
	uf.connect(1, 2);
	if (uf.isConnected(1, 2))
		cout << "connected" << endl;
	if (!uf.isConnected(1, 3))
		cout << "not connected" << endl;

	return 0;
}