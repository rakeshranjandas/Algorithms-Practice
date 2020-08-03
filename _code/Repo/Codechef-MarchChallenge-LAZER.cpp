#include<iostream>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

int findCrossing(int a[], int n, int x1, int x2, int y) {

	int dist, last_dist = a[x1] - y;
	bool counted_for_zero = false;

	int c = 0;

	for (int i = x1; i <= x2; i++) {
		dist = a[i] - y;

		if (dist == 0 && !counted_for_zero) {
			c++;
			counted_for_zero = true;

		} else {

			if ((last_dist > 0 && dist < 0) || (last_dist < 0 && dist > 0))
				c++;

			counted_for_zero = false;
		}

		last_dist = dist;
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

		int a[n+1];
		for (int i = 1; i < n+1; i++)
			cin >> a[i];

		int x1, x2, y;
		for (int i = 0; i < q; i++) {
			cin >> x1 >> x2 >> y;
			cout << findCrossing(a, n+1, x1, x2, y) << endl;
		}
	}

	return 0;
}