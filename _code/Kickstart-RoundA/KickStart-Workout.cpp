#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILE_WR freopen("../input.txt", "r", stdin);\
	freopen("../output.txt", "w", stdout);
#define deb(x)	cout << #x << " " << x << endl;

bool check(int a[], int n, int k, int val) {

	for (int i = 0; i < n-1; i++) {
		if (a[i+1] - a[i] > val) {
			k -= ceil((double)(a[i+1] - a[i]) / val) - 1;

			if (k < 0)
				return false;
		}
	}

	return true;
}

int workout(int a[], int n, int k) {

	int cur_max_diff = 0;
	for (int i = 0; i < n-1; i++)
		cur_max_diff = max(a[i+1] - a[i], cur_max_diff);

	int l = 1, r = cur_max_diff, mid;

	while (l < r) {

		mid = (l+r) / 2;

		if (check(a, n, k, mid))
			r = mid;

		else
			l = mid+1;
	}

	return r;
}

int main() {

	FILE_WR;
	IOS;

	int t;
	cin >> t;

	for (int t_i = 1; t_i <= t; t_i++) {

		int n, k;
		cin >> n >> k;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		cout << "Case #" << t_i << ": " << workout(a, n, k) << endl;
	}


	return 0;
}