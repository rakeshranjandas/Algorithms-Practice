#include<iostream>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

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
		long long int l, r;
		cin >> l >> r;
		cout << ((l+r) / 2) << endl;
	}

	return 0;
}