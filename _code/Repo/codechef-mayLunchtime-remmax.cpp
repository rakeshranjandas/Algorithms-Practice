#include<iostream>
using namespace std;

string minusOne(string s) {

	int digit;

	for (int i = s.length()-1; i >=0 ; i--) {
		digit = (s[i] - '0') - 1;

		if (digit >= 0) {
			s[i] = '0' + digit;
			break;
		}

		s[i] = '9';
	}

	return s;
}

string reverseMaximum(string s) {

	// Return that number if only one digit
	if (s.length() == 1)
		return s;

	string str = s;
	int lastDigitIndex = s.length() - 1;

	while (str[lastDigitIndex] != '9')
		str = minusOne(str);


	// Trim left 0's. Check if length is same. if not then????. If same then return reverse(str)


	return str;
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
		string s;
		cin >> s;

		cout << reverseMaximum(s) << endl;
	}

	return 0;
}