#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long int largestRect(long long int a[], int n) {

	stack<pair<long long int, int>> st;
	long long int max_area = 0;

	for (int i = 0; i < n; i++) {

		int ind = i;

		while (!st.empty() && st.top().first > a[i]) {
			auto popped = st.top();
			ind = popped.second;
			max_area = max(max_area, popped.first * (i-ind));
			st.pop();
		}


		st.push({a[i], ind});
	}

	while (!st.empty()) {
		auto popped = st.top();

		max_area = max(max_area, popped.first * (n-popped.second));

		st.pop();
	}

	return max_area;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		int n;
		cin >> n;

		if (n == 0)
			break;

		long long int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		cout << largestRect(a, n) << endl;
	}

	return 0;
}