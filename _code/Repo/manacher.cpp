#include<iostream>
using namespace std;

string modifyString(string s) {
	string s1 = "";

	for (auto c: s) {
		s1 += "#";
		s1 += c;
	}

	return s1 + "#";
}

string manacherLongestPalindrome(string s) {
	s = modifyString(s);

	int lp[s.length()+1];
	int i = 0, c = 0, r = 0;

	while (i < n) {
		
	}

	return s;
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
		cout << manacherLongestPalindrome(s) << endl;
	}

	return 0;
}