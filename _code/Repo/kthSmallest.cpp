#include<iostream>
using namespace std;

void swap(int a[], int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

int quickSort(int a[], int lo, int hi, int k) {

	//cout << lo << " " << hi << endl;
	int pos = lo-1;

	for (int i = lo; i < hi; i++) {
		if (a[i] < a[hi])
			swap(a, i, ++pos);
	}

	swap(a, hi, ++pos);

	return pos;
}

int quickSortKth(int a[], int lo, int hi, int k) {

	//cout << ">>>" << lo << " " << hi << endl;
	if (lo > hi)
		return -1;

	int pivot = quickSort(a, lo, hi, k);

	//cout << "pivot = " << pivot << endl;
	for (int i = lo; i <= hi; i++)
		//cout << a[i] << " ";
	//cout << endl;

	if (pivot == k-1)
		return a[pivot];

	else if (pivot < k-1)
		return quickSortKth(a, pivot+1, hi, k);

	else
		return quickSortKth(a, lo, pivot-1, k);
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

		int k;
		cin >> k;

		cout << quickSortKth(a, 0, n-1, k) << endl;
	}

	return 0;
}