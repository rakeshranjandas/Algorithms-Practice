#include<iostream>
#include <assert.h>
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

		assert(n%2 == 1);

		int a[n][n];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];

		// Upper Triangle sum
		int upSum = 0;
		for (int i = 0; i <= n/2; i++) {
			for (int j = i; j < n-i; j++) {
				// cout << "( " << i << "," << j << " )";
				upSum += a[i][j];
			}
		}

		// cout << "upsum = " << upSum << endl;

		// Right Triangle sum
		int rightSum = 0;
		for (int i = 0; i <= n/2; i++) {
			for (int j = i; j < n-i; j++) {

				// cout << "( " << j << "," << n-1-i << " )";
				rightSum += a[j][n-1-i];
			}
		}

		// cout << "rightSum = " << rightSum << endl;

		// Down Triangle sum
		int downSum = 0;
		for (int i = 0; i <= n/2; i++) {
			for (int j = i; j < n-i; j++) {
				// cout << "( " << n-1-i << "," << j << " )";
				downSum += a[n-1-i][j];
			}
		}

		// cout << "downSum = " << downSum << endl;

		// Left Triangle sum
		int leftSum = 0;
		for (int i = 0; i <= n/2; i++) {
			for (int j = i; j < n-i; j++) {

				// cout << "( " << j << "," << i << " )";
				leftSum += a[j][i];
			}
		}

		// cout << "leftSum = " << leftSum << endl;

		cout << max(leftSum, max(rightSum, max(upSum, downSum))) << endl;

	}

	return 0;
}