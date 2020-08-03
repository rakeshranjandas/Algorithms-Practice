#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;
#define N 201
// #define N 5

typedef long long int ll;

void printV(vector<vector<int>> v) {
	for (int i = 1; i < v.size(); i++) {
		cout << i << " : ";
		for (auto x: v[i])
			cout << x << " ";
		cout << endl;
	}
}

int maxThreeBlockSubseq(int a[], int n) {
	vector<vector<int>> v(N, vector<int>(n+1, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < N; j++)
			v[j][i+1] = v[j][i];

		v[a[i]][i+1]++;
	}

	// printV(v);

	int max_len = 1;

	for (int i = 1; i <= n; i++) {
		int cur_count = v[a[i-1]][i];
		int required = v[a[i-1]][n] - v[a[i-1]][i];

		// deb(i);
		// deb(cur_count);
		// deb(required);

		if (required <= 0)
			continue;

		if (required < v[a[i-1]][i])
			continue;

		auto it = upper_bound(v[a[i-1]].begin(), v[a[i-1]].end(), required);
		it--;

		if (it != v[a[i-1]].end()) {
			int ind = it - v[a[i-1]].begin();
			// cout << "ind " << ind << endl;

			for (int j = 1; j < N; j++) {
				// if (j == a[i-1])
				// 	continue;
				int len = 2*cur_count + v[j][ind]-v[j][i];
				// deb(j);
				// deb(len);
				max_len = max(max_len, len);
			}
		}
	}

	return max_len;
}

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		cout << maxThreeBlockSubseq(a, n) << endl;
	}

	return 0;
}