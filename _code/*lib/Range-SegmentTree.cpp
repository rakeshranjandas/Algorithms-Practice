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

/* NOTE: r is EXCLUSIVE */

class SegmentTree {
	int size;
	vector<LL> v;

	/* --- MODIFY APPROPRIATELY --- */
	LL NEUTRAL = 0;

	LL op(LL a, LL b) {
		return a+b;
	}

	/* --- END MODIFY APPROPRIATELY --- */

	void initV(int n) {
		size = 1;
		while (size < n)
			size *= 2;

		v.resize(2*size-1, NEUTRAL);
	}

	void build(VLL &a, int l, int r, int node) {

		if (r-l == 1) {
			v[node] = l >= SZ(a) ? NEUTRAL: a[l];
			return;
		}

		int mid = (l+r)/2;
		build(a, l, mid, 2*node+1);
		build(a, mid, r, 2*node+2);

		v[node] = op(v[2*node+1], v[2*node+2]);
	}

	void set(int ind, LL x, int l, int r, int node) {
		if (r-l == 1) {
			v[node] = x;
			return;
		}

		int mid = (l+r)/2;
		if (ind < mid)
			set(ind, x, l, mid, 2*node+1);
		else
			set(ind, x, mid, r, 2*node+2);

		v[node] = op(v[2*node+1], v[2*node+2]);
	}

	LL rangeOp(int rl, int rr, int l, int r, int node) {

		if (r <= rl || rr <= l)
			return NEUTRAL;

		if (rl <= l && r <= rr)
			return v[node];

		int mid = (l+r)/2;
		auto sl = rangeOp(rl, rr, l, mid, 2*node+1);
		auto sr = rangeOp(rl, rr, mid, r, 2*node+2);

		return op(sl, sr);

	}

	public:

	SegmentTree(int n) {
		initV(n);
	}

	SegmentTree(VLL &a) {
		int n = SZ(a);
		initV(n);
		build(a, 0, size, 0);
	}

	void set(int ind, LL x) {
		set(ind, x, 0, size, 0);
	}

	LL rangeOp(int rl, int rr) {
		return rangeOp(rl, rr, 0, size, 0);
	}
};

void solve() {
	VLL a= {3, 5, 1, 2, 1};
	SegmentTree st = SegmentTree(a);

	st.set(3, 21);
	LL sum = st.rangeOp(0, 4);
	DEB(sum);
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