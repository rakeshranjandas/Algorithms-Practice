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

int sumTwoMidElements(int a[], int b[], int n, int lo, int hi) {

	// cout << lo << " " << hi << endl;

	// if (n > m)
	// 	return sumTwoMidElements(b, m, a, n, 0, m);

	// int median_size = n;

	int fi = (lo+hi) / 2,
		si = n - fi;

	int la = assignMinMax(a, n, fi-1),
		ra = assignMinMax(a, n, fi);

	int lb = assignMinMax(b, n, si-1),
		rb = assignMinMax(b, n, si);

	// cout << "a " << la << " " << ra << endl;
	// cout << "b " << lb << " " << rb << endl;


	if (la <= rb && lb <= ra)
		return max(la, lb) + min(ra, rb);

	if (la > rb)
		return sumTwoMidElements(a, b, n, lo, fi-1);
	else
		return sumTwoMidElements(a, b, n, fi+1, hi);
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
		
		int b[n];
		for (int i = 0; i < n; i++)
			cin >> b[i];

		cout << sumTwoMidElements(a, b, n, 0, n) << endl;
	}

	return 0;
}