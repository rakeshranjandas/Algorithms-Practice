#include<iostream>
#include<climits>
using namespace std;

int maxOnesOnFlip(int a[], int n) {

	int total_ones = 0;

	// Set 0 as 1 and 1 as -1
	for (int i = 0; i < n; i++) {
		total_ones += a[i];
		a[i] = (a[i] == 0) ? 1 : -1;
	}

	// Find max sum subarray in this modified array
	int max_so_far = INT_MIN, max_ending_here = 0;
	for (int i = 0; i < n; i++) {

		max_ending_here += a[i];

		max_so_far = max(max_so_far, max_ending_here);

		if (max_ending_here < 0)
			max_ending_here = 0;
	}

	return max(total_ones, total_ones + max_so_far);

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

		cout << maxOnesOnFlip(a, n) << endl;
	}

	return 0;
}