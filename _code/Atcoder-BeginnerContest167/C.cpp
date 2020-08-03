#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

#define N 13
#define M 14

bool skillEnough(int num, int b[][M], int n, int m, int x, int *cost) {
	*cost = 0;
	int skill[m+1] = {0};

	for (int i = 0; i < n; i++) {
		if ((num >> i) & 1) {
			*cost += b[i][0];

			for (int j = 1; j <= m; j++)
				skill[j] += b[i][j];
		}
	}

	for (int i = 1; i <= m; i++) {
		if (skill[i] < x)
			return false;
	}

	return true;
}

int findMinMoney(int b[][M], int n, int m, int x) {

	int mm = INT_MAX, cost;

	for (int num = 1; num < (2 << n); num++) {
		if (skillEnough(num, b, n, m, x, &cost))
			mm = min(mm, cost);
	}

	return mm == INT_MAX ? -1 : mm;
}

int main() {

	IOS

	int n, m, x;
	cin >> n >> m >> x;

	int b[N][M];

	for (int i = 0; i < n; i++)
		for (int j = 0; j <= m; j++)
			cin >> b[i][j];

	cout << findMinMoney(b, n, m, x) << endl;

	return 0;
}