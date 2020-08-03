#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool lexicoCompare(string a, string b) {

	bool retVal = atoi((a+b).c_str()) > atoi((b+a).c_str());
	return retVal;
}

void largestNumber(string s[], int n) {
	sort(s, s+n, lexicoCompare);

	for (int i = 0; i < n; i++)
		cout << s[i];
	cout << endl;
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
		int n;
		cin >> n;

		string s[n];
		for (int i = 0; i < n; i++)
			cin >> s[i];

		largestNumber(s, n);
	}

	return 0;
}

// 9534330
// 6054854654