#include<iostream>
using namespace std;

bool isVowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	return false;
}

int cv(string s, int n) {
	int count = 0;

	for (int i = 0; i < n-1; i++) {
		if (isVowel(s[i]))
			continue;

		if (isVowel(s[i+1])) {
			count++;
			i++;
		}
	}

	return count;
}

int main() {

	// #ifndef ONLINE_JUDGE
	// 	freopen("../input.txt", "r", stdin);
	// 	freopen("../output.txt", "w", stdout);
	// 	#else
	// #endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		string s;
		cin >> s;

		cout << cv(s, n) << endl;
	}

	return 0;
}