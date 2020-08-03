#include<iostream>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

int countOnes(int n) {

	int c_1 = 0;

	while (n > 0) {
		if (n & 1)
			c_1++;

		n = n/2;
	}

	return c_1;
}

int engXor(int a[], int n) {

	int c = 0;
	for (int i = 0; i < n; i++) {
		if ((countOnes(a[i]) % 2) == 0)
			c++;
	}

	return c;
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
		int n, q;
		cin >> n >> q;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int count_even_ones = engXor(a, n);

		int p;
		string s = "";

		for (int i = 0; i < q; i++) {
			cin >> p;

			if (countOnes(p) % 2 == 0) {
				// cout << count_even_ones << " " << (n - count_even_ones) << endl;
				s += to_string(count_even_ones) + " " + to_string(n - count_even_ones) + "\n";

			} else {
				// cout << (n - count_even_ones) << " " << count_even_ones << endl;
				s +=  to_string(n - count_even_ones) + " " + to_string(count_even_ones) + "\n";
			}
		}

		cout << s << endl;
	}

	return 0;
}