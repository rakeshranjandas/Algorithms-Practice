#include<iostream>
#include<climits>
using namespace std;

float medianOfTwoSorted(int a[], int n, int b[], int m, int lo, int hi) {

	// cout << lo << " " << hi << endl;

	if (n > m)
		return medianOfTwoSorted(b, m, a, n, 0, m);

	int median_size = (m+n) - ((m+n) / 2);

	int fi = (lo+hi) / 2,
		si = median_size - fi;

	int la = (fi <= 0) ? INT_MIN : a[fi-1],
		ra = (fi >= n) ? INT_MAX : a[fi];

	int lb = (si <= 0) ? INT_MIN : b[si-1],
		rb = (si >= m) ? INT_MAX : b[si];

	// cout << "a " << la << " " << ra << endl;
	// cout << "b " << lb << " " << rb << endl;


	if (la <= rb && lb <= ra)
		return ((m+n) % 2 == 1) ? (float) max(la, lb) : ((float)(max(la, lb)+ min(ra, rb))/ 2);

	if (la > rb)
		return medianOfTwoSorted(a, n, b, m, lo, fi-1);
	else
		return medianOfTwoSorted(a, n, b, m, fi+1, hi);
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

		int m;
		cin >> m;
		
		int b[m];
		for (int i = 0; i < m; i++)
			cin >> b[i];

		cout << medianOfTwoSorted(a, n, b, m, 0, n) << endl;
	}

	return 0;
}