#include<iostream>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

void exchangeInString(string &str, int ind1, int ind2) {
	char temp = str[ind2];
	str[ind2] = str[ind1];
	str[ind1] = temp;
}

void largestNumberInSwaps(string s, int k, int now, string &max_s) {

	if (now >= s.size())
		return;

	if (max_s.compare(s) < 0)
		max_s = s;

	if (k == 0)
		return;


	// If swapped from the middle
	for (int i = now+1; i < s.size(); i++) {
		if (s[now] < s[i]) {
			string new_s = s;

			exchangeInString(new_s, now, i);

			largestNumberInSwaps(new_s, k-1, now+1, max_s);
		}
	}

	// If nothing is swapped this time
	largestNumberInSwaps(s, k, now+1, max_s);
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
		int k;
		string s;
		cin >> k >> s;

		string max_s = s;

		largestNumberInSwaps(s, k, 0, max_s);

		cout << max_s << endl;

	}

	return 0;
}