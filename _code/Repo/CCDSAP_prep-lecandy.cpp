#include<iostream>
#include <numeric>
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
		int n, c;
		cin >> n >> c;
		
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int sum_candies = accumulate(a, a+n, 0);

		cout << (sum_candies <=  c ? "Yes" : "No") << endl;
	}

	return 0;
}