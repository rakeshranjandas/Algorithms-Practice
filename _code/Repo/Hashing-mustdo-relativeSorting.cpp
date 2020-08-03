#include<iostream>
#include<bits/stdc++.h>
using namespace std;

unordered_map<int, int> order;

bool customSort(int a, int b) {
	return order[a] < order[b];
}

void relativeSort(int a[], int n, int b[], int m) {

	// Clear order map
	order.clear();

	// Put elements in hashmap
	for (int i = 0; i < m; i++)
		order[b[i]] = i;

	// for (auto x: order)
	// 	cout << " " << x.first << "(" << x.second << "), ";
	// cout << endl;

	// Partition array a into 2 parts - custom ordered and natural ordered
	int p = -1;	// Ending index of the partition
	int temp;	// To swap variables

	for (int i = 0; i < n; i++) {

		// Swap if elements is present in 'order' map
		if (order.find(a[i]) != order.end()) {
			temp = a[i];
			a[i] = a[p+1];
			a[p+1] = temp;
			p++;
		}
	}

	// Sort first half, with relative ordering
	sort(a, a+p+1, customSort);

	// Sort second half, with natural ordering
	sort(a+p+1, a+n);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
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
		int n, m;
		cin >> n >> m;

		int a[n], b[m];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		for (int i = 0; i < m; i++)
			cin >> b[i];

		relativeSort(a, n, b, m);

	}

	return 0;
}