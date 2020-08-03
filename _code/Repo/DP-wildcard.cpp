#include<iostream>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

int wildCard(string pattern,string str) {

	if (pattern.size() == 0 && str.size() == 0)
		return 1;

	if (pattern.size() == 0)
		return 0;

	// *
	if (pattern[0] == '*') {
		int null_chosen = wildCard(pattern.substr(1), str);

		int matched = 0;
		if (str.size() > 0)
			matched = wildCard(pattern, str.substr(1));

		return null_chosen || matched;
	}

	// ?
	if (pattern[0] == '?')
		return wildCard(pattern.substr(1), str.substr(1));

	// w
	if (pattern[0] == str[0])
		return wildCard(pattern.substr(1), str.substr(1));

	return 0;
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
		string pat, str;
		cin >> pat >> str;

		cout << wildCard(pat, str) << endl;
	}

	return 0;
}