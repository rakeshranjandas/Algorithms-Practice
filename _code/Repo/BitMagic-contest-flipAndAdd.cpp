#include<iostream>
#include<cmath>
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

		int num_bin_digits = ((int) log2(n)+1);
		int flipped;

		if (num_bin_digits % 2 == 1)
			flipped = n & 0x55555555;
		
		else
			flipped = n & 0xAAAAAAAA;		

		cout << (n + flipped) << endl;
	}

	return 0;
}