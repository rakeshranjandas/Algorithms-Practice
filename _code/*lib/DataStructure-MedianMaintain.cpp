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

class MedianMaintain {
	priority_queue<LL> lpq;
	minpq<LL> rpq;
	LL lsum, rsum;

	void balance() {
		while (SZ(rpq)-SZ(lpq) > 1) {
			LL rtop = rpq.top();
			rpq.pop();
			rsum -= rtop;

			lpq.push(rtop);
			lsum += rtop;
		}

		while (SZ(lpq) > SZ(rpq)) {
			LL ltop = lpq.top();
			lpq.pop();
			lsum -= ltop;

			rpq.push(ltop);
			rsum += ltop;
		}
	}

	public:

	MedianMaintain() {
		lsum = 0, rsum = 0;
	}

	void insert(LL x) {
		if (rpq.empty()) {
			rpq.push(x);
			rsum += x;
			return;
		}

		if (x >= rpq.top()) {
			rpq.push(x);
			rsum += x;

		} else {
			lpq.push(x);
			lsum += x;
		}

		balance();
	}

	LL getMedian() {
		return SZ(rpq) == SZ(lpq) ? lpq.top(): rpq.top();
	}

	PLL medianCostPair() {
		LL median = getMedian();
		LL lc = rsum - median * SZ(rpq);
		LL rc = median * SZ(lpq) - lsum;
		return {median, lc + rc};
	}
};

void solve() {

	MedianMaintain mm = MedianMaintain();
	mm.insert(2);
	mm.insert(4);
	mm.insert(5);
	mm.insert(1);

	cout << mm.getMedian() << endl;
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