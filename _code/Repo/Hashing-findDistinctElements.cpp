#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findDistinct(int* a, int n) {

	unordered_set<int> s;

	for (int j = 0; j < n; j++)
		s.insert(*(a+j));

	unordered_set<int> :: iterator it;
	for (int i = 1; i < n; i++)
		for (int j = 0; j < n; j++) {

			it = s.find(*((a + i*n) +j));

			if (it != )
		}

	return 1;
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

		int a[n][n];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];

		cout << findDistinct((int*)a, n) << endl;
	}

	return 0;
}