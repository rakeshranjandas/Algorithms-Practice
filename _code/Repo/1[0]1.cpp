#include<iostream>
using namespace std;

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		int count = 0;
		bool oneFound = false, zeroFound = false;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '1') {
				if (oneFound && zeroFound) {
					count++;
					zeroFound = false;

				} else {
					oneFound = true;
				}

			} else if (s[i] == '0' && oneFound) {
				zeroFound = true;

			} else {
				oneFound = false;
				zeroFound = false;
			}
		}

		cout << count << endl;
	}

	return 0;
}