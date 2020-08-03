#include<iostream>
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

		string s;
		cin >> s;

		int slen = s.length();

		int a[26] = {0};

		int i;

		for (i = 0; i < slen/2; i++)
			a[s[i] - 'a']++;

		bool lapin = true;

		if (slen % 2 == 1)
			i++;

		for (; i < slen; i++) {
			if (a[s[i] - 'a'] == 0) {
				lapin = false;
				break;
			}

			a[s[i] - 'a']--;
		}

		cout << (lapin ? "YES" : "NO") << endl;
	}

	return 0;
}