#include<iostream>
#include<cstring>
using namespace std;

bool dps(string s) {

	int a[26];
	memset(a, 0, sizeof(int) * 26);

	for (auto c: s) {
		a[c - 'a']++;
	}

	int evenCount = 0, oddCount = 0;
	for (int i = 0; i < 26; i++) {
		if (a[i] > 0) {
			if (a[i] & 1)
				oddCount++;
			else
				evenCount++;
		}
	}

	bool canDPS = false;

	if (s.length() & 1) {
		if (oddCount == 1 || oddCount == 3)
			canDPS = true;

	} else {
		if (oddCount == 2)
			canDPS = true;
	}

	return canDPS;
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
		string s;
		cin >> s;

		cout << (dps(s) ? "DPS": "!DPS") << endl;
	}

	return 0;
}