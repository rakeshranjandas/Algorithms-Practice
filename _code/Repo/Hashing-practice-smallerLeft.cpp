#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void smallerOnLeft(int a[], int n) {

	set<int> seen;
	set<int> :: iterator seen_it;
	int dist;

	for (int i = 0; i < n; i++) {

		seen.insert(a[i]);
		seen_it = seen.find(a[i]);
		
		if (seen_it == seen.begin())
			cout << "-1 ";

		else
			cout << *(--seen_it) << " ";
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

	while (t--) {
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		smallerOnLeft(a, n);
	}

	return 0;
}