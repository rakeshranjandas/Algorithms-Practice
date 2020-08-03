#include<iostream>
#include <iomanip>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

bool validIndex(int i, int j, int r, int c) {
	return i <= r && j <= c;
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
		int k, r, c;
		cin >> k >> r >> c;

		double a[r+1][c+1] = {0}, overflow;
		a[1][1] = k;

		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if (a[i][j] > 1) {
					overflow = a[i][j] - 1;
					a[i][j] = 1;

					if (validIndex(i+1, j, r, c))
						a[i+1][j] += overflow/2;

					if (validIndex(i+1, j+1, r, c))
						a[i+1][j+1] += overflow/2;
				}
			}
		}

		cout << std::fixed << setprecision(6) << a[r][c] << endl;
	}

	return 0;
}