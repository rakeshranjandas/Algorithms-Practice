#include<iostream>
using namespace std;

int fillSquares(int n) {

	if (n <= 3)
		return 0;

	if (n == 4)
		return 1;

	return ((n-2)/2) + fillSquares(n-2);
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

		cout << fillSquares(n) << endl;
	}

	return 0;
}