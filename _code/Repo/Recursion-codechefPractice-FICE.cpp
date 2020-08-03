#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int numWaysFireIceHelper(int n, int m, int a[]) {

	if (n == 0)
		return 0;

	if (n == 2 || n == 1)
		return 1;

	if (a[n] != 0)
		return a[n];

	int res = 0;

	for (int i = 1; i < n; i+=2)
		res = (res + (numWaysFireIceHelper(n-i, m, a))) % m;

	a[n] = (n%2 == 0 ? res : ++res)%m;

	return a[n];
}

int numWaysFireIce(int n, int m) {
	int a[n+1] = {0};

	a[0] = 0;
	a[1] = 1;
	a[2] = 1;

	return numWaysFireIceHelper(n, m, a);
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

	// for (int i = 0; i < 30; i++)
	// 	cout << i << ": "<< numWaysFireIce(i, 1000) << endl;

	while (t--) {
		int n, m;
		cin >> n >> m;

		cout << (2*numWaysFireIce(n, m)) % m << endl;
	}

	return 0;
}

// 0 	0
// 1 	1
// 2 	1
// 3 	2
// 4 	3
// 5 	5
// 6 	8
// 7 	13
// 8 	21
// 9 	34
// 10 	55
// 11 	89
// 12 	144
// 13 	233
// 14 	377
// 15 	610
// 16 	987
// 17 	1597
// 18 	2584
// 19 	4181
// 20 	6765
// 21 	10946
// 22 	17711
// 23 	28657
// 24 	46368
// 25 	75025
// 26 	121393
// 27 	196418
// 28 	317811
// 29 	514229
// 30 	832040