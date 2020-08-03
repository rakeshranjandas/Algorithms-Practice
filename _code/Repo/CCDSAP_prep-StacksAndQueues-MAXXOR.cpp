#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxXorSec(int a[], int n) {

	stack<int> st;
	int maxXor = 0;

	for (int i = 0; i < n; i++) {

		while (!st.empty() && st.top() < a[i]) {
			maxXor = max(maxXor, (st.top() ^ a[i]));
			st.pop();
		}

		if (!st.empty())
			maxXor = max(maxXor, (st.top() ^ a[i]));

		st.push(a[i]);
	}

	return maxXor;
}

int main() {

	// #ifndef ONLINE_JUDGE
	// 	freopen("../input.txt", "r", stdin);
	// 	freopen("../output.txt", "w", stdout);
	// 	#else
	// #endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << maxXorSec(a, n) << endl;

	return 0;
}