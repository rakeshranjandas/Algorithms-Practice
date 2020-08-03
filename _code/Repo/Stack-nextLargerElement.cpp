#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string nextLargerElementString(long long int a[], int n) {

	stack<long long int> st;
	string res;

	for (int i = n-1; i >= 0; i--) {

		while (!st.empty() && st.top() <= a[i])
			st.pop();

		res = (st.empty() ? "-1" : to_string(st.top())) + " " + res;
		st.push(a[i]);
	}

	return res;
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

		cout << nextLargerElementString(a, n) << endl;
	}

	return 0;
}