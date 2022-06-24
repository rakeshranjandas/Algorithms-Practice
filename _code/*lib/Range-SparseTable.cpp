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
typedef vector<int> VI;
typedef vector<LL> VL;

int lg2(int n) {
	return floor(log2(n));
}

class RMQ {
	int n, p;
	vector<vector<int>> dp;

	public:
	RMQ(vector<int> &v) {
		n = v.size();
		p = lg2(n);
		dp.resize(p+1, vector<int>(n));

		for (int col = 0; col < n; col++)
			dp[0][col] = v[col];

		for (int i = 1; i <= p; i++) {
			for (int col = 0; (col + (1<<i)) <= n; col++) {
				dp[i][col] = min(dp[i-1][col], dp[i-1][col+(1<<(i-1))]);
			}
		}
	}

	int findMin(int l, int r) {
		/* NOTE: r is INCLUSIVE */
		int lr = lg2(r-l+1);
		int left = dp[lr][l];
		int right = dp[lr][r-(1<<lr)+1];
		return min(left, right);
	}
};

int main() {

	IOS

	int n;
	cin >> n;
	vector<int> a(n);
	REP(i, n)
		cin >> a[i];

	RMQ rmq(a);

	int q;
	cin >> q;

	REP(i, q) {
		int l, r;
		cin >> l >> r;
		cout << rmq.findMin(l, r) << endl;
	}

	return 0;
}