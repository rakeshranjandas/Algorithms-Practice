#include<iostream>
#include<climits>
using namespace std;

int assignMinMax(int a[], int n, int index) {

	if (index < 0)
		return INT_MIN;

	if (index >= n)
		return INT_MAX;

	return a[index];
}

int kthOfTwoSorted(int a[], int n, int b[], int m, int lo, int hi, int k) {

	// cout << lo << " " << hi << endl;

	if (n > m)
		return kthOfTwoSorted(b, m, a, n, 0, m, k);

	int fi = (lo+hi) / 2,
		si = k - fi;

	// cout << "ind " << fi << " " << si << endl;

	int la = assignMinMax(a, n, fi-1),
		ra = assignMinMax(a, n, fi);

	int lb = assignMinMax(b, m, si-1),
		rb = assignMinMax(b, m, si);

	// int la = (fi <= 0) ? INT_MIN : a[fi-1],
	// 	ra = (fi >= n) ? INT_MAX : a[fi];

	// int lb = (si <= 0) ? INT_MIN : b[si-1],
	// 	rb = (si >= m) ? INT_MAX : b[si];

	// cout << "a " << la << " " << ra << endl;
	// cout << "b " << lb << " " << rb << endl;


	if (la <= rb && lb <= ra)
		return max(la, lb);

	if (la > rb)
		return kthOfTwoSorted(a, n, b, m, lo, fi-1, k);
	else
		return kthOfTwoSorted(a, n, b, m, fi+1, hi, k);
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
		int n, m, k;
		cin >> n >> m >> k;
		
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int b[m];
		for (int i = 0; i < m; i++)
			cin >> b[i];

		cout << kthOfTwoSorted(a, n, b, m, 0, n, k) << endl;
	}

	return 0;
}