#include<iostream>
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
		long long int a, b;
		cin >> a >> b;

		cout << (a > b ? a/b : b/a) << endl;

	}

	return 0;
}