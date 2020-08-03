#include<iostream>
using namespace std;

void frequencies(int a[], int n) {

	for (int i = 0; i < n; i++)
		a[i]--;

	for (int i = 0; i < n; i++)
		a[ ((a[i]) % n) ] += n;

	for (int i = 0; i < n; i++) {

		cout << (a[i] / n) << " ";
		// cout << a[i] << " ";
	}

	cout << endl;
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
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		frequencies(a, n);
	}

	return 0;
}