#include<iostream>
#include<cmath>
using namespace std;

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
		int n;
		cin >> n;

		int x = (int) log2(n), c = 0;
		int two_pow = 1 << x;

		int r, s, o;

		while (two_pow) {

			r = n / two_pow;
			s = n % two_pow;
			o = 0;

			if (r % 2 != 0)
				o += s+1;

			o += (r/2)* two_pow;

			c += o;

			// cout << two_pow <<  " " << o << endl;

			two_pow >>= 1;
		}

		cout << c << endl;

	}

	return 0;
}