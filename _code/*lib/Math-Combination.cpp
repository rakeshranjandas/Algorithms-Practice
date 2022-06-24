#include<iostream>
#include<bits/stdc++.h>
using namespace std;

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
#define DEB(...) _GET_OVERRIDE(__VA_ARGS__, \
	_DBM_6, _DBM_5, _DBM_4, _DBM_3, _DBM_2, _DBM_1)(__VA_ARGS__) cout << endl
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
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;

const int M = 1e9+7;
/*------------------------------------------------------------------------*/

class Combination{
	VLL fact, inv_fact;
	int limit;

	LL modPow(LL n, LL e) {
		LL b = n;
		LL res = 1;

		while (e) {
			if (e&1)
				res = (res*b) % M;
			b = (b*b) % M;
			e >>= 1;
		}

		return res;
	}

	LL inv(LL n) {
		return modPow(n, M-2);
	}

	public:
	Combination(int sz) {
		limit = sz+1;
		fact.resize(limit);
		inv_fact.resize(limit);

		fact[0] = inv_fact[0] = 1;

		FOR(i, 1, limit) {
			fact[i] = (fact[i-1] * i) % M;
			inv_fact[i] = inv(fact[i]);
		}
	}

	LL eval(int n, int r) {
		return (((fact[n] * inv_fact[r])%M)*inv_fact[n-r])%M;
	}
};

Combination C = Combination(2*1e5+2);

int main() {

	IOS
	DEB(C.eval(5, 2));
	DEB(C.eval(6, 2));

	return 0;
}