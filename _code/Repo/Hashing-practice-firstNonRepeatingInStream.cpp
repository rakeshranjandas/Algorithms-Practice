#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printFirstNonRepeating(char s[], int n) {

	queue<char> q;
	map<char, int> m;

	for (int i = 0; i < n; i++) {
		// cout << "\n->" << s[i] << endl;

		m[s[i]]++;

		if (m[s[i]] == 1)
			q.push(s[i]);
		
		// cout << q.front() << " qfront\n";

		while (!q.empty() && m[q.front()] > 1)
			q.pop();

		if (q.empty())
			cout << "-1 ";

		else 
			cout << q.front() << " ";
	}

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
	cin.ignore();

	while (t--) {
		int n;
		cin >> n;

		char s[n];
		for (int i = 0; i < n; i++)
			cin >> s[i];

		printFirstNonRepeating(s, n);
	}

	return 0;
}