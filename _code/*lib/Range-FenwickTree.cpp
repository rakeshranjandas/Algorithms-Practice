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
#define ALL(a) (a).begin(),(a).end()A
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

class FenwickTree {
	VLL tree;
	int n;

	LL prefixSum(int i) {
		LL sum = 0LL;
		while (i != 0) {
			sum += tree[i];
			i -= LSB(i); // or, i &= ~LSB(i);
		}

		return sum;
	}

	int LSB(int i) {
		// Responsibilty size of current index
		return i & -i;
	}

	void init(VLL arr) {
		tree = arr;
		n = arr.size();

		REP(i, n) {
			int j = i + LSB(i);
			if (j < n)
				tree[j] += tree[i];
		}
	}

	public:

	FenwickTree(int n) {
		VLL arr(n);
		init(arr);
	}

	FenwickTree(VLL arr) {
		init(arr);
	}
	
	LL sum(int l, int r) {
		// [l, r]
		return prefixSum(r) - prefixSum(l-1);
	}

	void add(int i, LL k) {
		while (i < n) {
			tree[i] += k;
			i += LSB(i);
		}
	}

	void set(int i, LL k) {
		LL value = sum(i, i);
		LL more = k - value;
		add(i, more);
	}
};

int main() {

	IOS

	// int t;
	// cin >> t;

	// while (t--) {
	//     solve();
	// }

	return 0;
}