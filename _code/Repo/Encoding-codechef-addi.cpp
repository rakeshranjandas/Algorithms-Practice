#include<iostream>
using namespace std;

int unsetBits(long long int n, int count) {
	
	if (n == 0)
		return count;

	if (!(n & 1))
		count++;

	return unsetBits(n/2, count);
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
		long long int n;
		cin >> n;

		cout << unsetBits(n, 0) << endl;
	}

	return 0;
}