#include<iostream>
using namespace std;

bool isTimePossible(int a[], int n, int val, int k) {

	int time = 0, person = 1;

	for (int i = 0; i < n; i++) {

		if (time + a[i] <= val)
			time += a[i];

		else {
			person++;

			if (person > k)
				return false;

			if (a[i] > val)
				return false;

			time = a[i];
		}
	}

	return true;
}

int findMinPaintTime(int a[], int n, int l, int r, int k) {

	// cout << "l = " << l << ", r = " << r << endl;
	
	if (l == r)
		return l;

	int mid = (l+r) / 2;

	if (mid == l)
		return r;

	bool timePossible = isTimePossible(a, n, mid, k);

	// cout << " mid = " << mid << " possible = " << timePossible << endl;

	if (timePossible)
		return findMinPaintTime(a, n, l, mid, k); 

	else
		return findMinPaintTime(a, n, mid, r, k);
}

int minPaintTime(int a[], int n, int k) {

	int maxTime = 0;
	for (int i = 0; i < n; i++)
		maxTime += a[i];

	return findMinPaintTime(a, n, 0, maxTime, k);
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
		int n, k;
		cin >> k >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		cout << minPaintTime(a, n, k) << endl;
	}

	return 0;
}