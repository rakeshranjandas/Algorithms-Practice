#include<iostream>
using namespace std;

int findCountOnes(int n) {
	int multTens = 1;
	int onesUnderFull = 0;
	int countOnes = 0, digit;
	int num = n;

	while (num > 0) {
		digit = num % 10;

		countOnes += digit * onesUnderFull;

		if (digit > 1)
			countOnes += multTens;

		else if (digit == 1)
			countOnes += (n % multTens) + 1;


		onesUnderFull = 10 * onesUnderFull + multTens;
		multTens *= 10;
		num /= 10;
	}

	return countOnes;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		cout << findCountOnes(n) << endl;
	}

	return 0;
}