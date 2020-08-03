#include<iostream>
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
		int n, k;
		cin >> n >> k;

		int q, r;
		int res = 0;

		while ((q = n/k)) {

			res += q;
			n = q + n%k;
		}

		cout << res << endl;
	}

	return 0;
}