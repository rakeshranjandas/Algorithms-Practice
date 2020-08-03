#include<iostream>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;
#define MOD 1000000007

long long int fast_exp(int b, int e) {

	long long int pows = b;
	long long int res = 1;

	while (e > 0) {

		if (e & 1)
			res = (res * pows) % MOD;

		pows = (pows * pows) % MOD;
		e >>= 1;
	}

	return res;
}

long long int colorWays(int m, int n) {
	return (fast_exp(3, m+n) * fast_exp(fast_exp(2, m), n)) % MOD;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int m, n;
		cin >> m >> n;

		cout << colorWays(m, n) << endl;
	}

	return 0;
}