#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

int canBuy(int house[], int n, int b) {
	
	sort(house, house+n);

	int i;

	for (i = 0; i < n; i++) {
		if (b-house[i] < 0)
			break;

		b -= house[i];
	}

	return i;
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

	for (int t_i = 1; t_i <= t; t_i++) {

		int n, b;
		cin >> n >> b;

		int house[n];
		for (int i = 0; i < n; i++)
			cin >> house[i];

		cout << "Case #" << t_i << ": " << canBuy(house, n, b) << endl;
	}

	return 0;
}