#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void nextLargerElementString(long long int a[], int n) {
	stack<long long int> st;
	st.push(0);

	// Initialise to -1
	long long int nextLarge[n];
	for (int i = 0; i < n; i++)
		nextLarge[i] = -1;

	for (int i = 0; i < n; i++) {
		while (!st.empty() && a[st.top()] < a[i]) {
			nextLarge[st.top()] = a[i];
			st.pop();
		}

		st.push(i);
	}

	for (int i = 0; i < n; i++)
		cout << nextLarge[i] << " ";
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
		
		long long int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		nextLargerElementString(a, n);
		cout << endl;
	}

	return 0;
}