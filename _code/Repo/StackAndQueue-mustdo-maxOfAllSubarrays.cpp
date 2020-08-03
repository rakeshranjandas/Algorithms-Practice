#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string allMax(int a[], int n, int k) {
	multiset<int, std::greater<int>> ms;

	for (int i = 0; i < k; i++)
		ms.insert(a[i]);

	string res = to_string(*(ms.begin()));

	for (int i = k; i < n; i++) {
		ms.erase((ms.find(a[i-k])));
		ms.insert(a[i]);
		res += " " + to_string(*(ms.begin()));
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
		int n, k;
		cin >> n >> k;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		cout << allMax(a, n, k) << endl;
	}

	return 0;
}