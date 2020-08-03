#include<iostream>
#include<climits>
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
		int n, m, k;
		cin >> n >> m >> k;


		// -1 conditions
		if (
			(m == 1 && n == 1)
			||
			(k > m && k > n)
		) {
			cout << "-1" << endl;
			continue;
		}

		//

		long long int a[n][m] = {0};

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> a[i][j];

		long long int a_2[n-1][m-1];

		for (int i = 0; i < n-1; i++) {
			for (int j = 0; j < m-1; j++) {
				a_2[i][j] = a[i][j] + a[i+1][j] + a[i][j+1] + a[i+1][j+1];
			}
		}

		long long int min_cost = LONG_MAX, cost, core_cost, cost_hor;

		for (int i = 0; i < n-1; i++) {
			for (int j = 0; j < m-1; j++) {
				core_cost = a_2[i][j];

				if (j+k-1 < n) {
					for (int l = j+2; l+2 <; l+=2)
				}

				if ()

			}
		}
	}

	return 0;
}