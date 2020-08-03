#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int score(int a[][5], int arr[]) {
	int sc = 0;

	for (int i = 0; i < 4; i++) {
		// cout << "------\n";
		for (int j = i; j+1 < 5; j+=2) {
			// deb(j);
			// deb(j+1);
			sc += a[arr[j]][arr[j+1]] + a[arr[j+1]][arr[j]];
		}
	}

	return sc;
}

void rec(int a[][5], int cur, int arr[], set<int> &s, int *res) {
	if (cur == 5) {
		// for (int i = 0; i < 5; i++)
		// 	cout << arr[i] << " ";
		// cout << endl;

		// deb(score(a, arr));

		*res = max(*res, score(a, arr));

		return;
	}

	for (int i = 0; i < 5; i++) {
		if (s.find(i) != s.end())
			continue;

		s.insert(i);
		arr[cur] = i;
		rec(a, cur+1, arr, s, res);
		s.erase(i);
	}
}

int main() {

	IOS

	int a[5][5];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> a[i][j];

	set<int> used;
	int arr[5];
	int res = 0;

	rec(a, 0, arr, used, &res);
	cout << res;

	return 0;
}