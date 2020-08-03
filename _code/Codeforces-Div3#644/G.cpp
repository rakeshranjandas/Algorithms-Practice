#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

void printColSum(int col_sum[], int m) {
	for (int i = 0; i < m; i++)
		cout << col_sum[i] << " ";
	cout << endl;
}

void printRes(string res[], int n) {
	for (int i = 0; i < n; i++)
		cout << res[i] << endl;
}

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
		int n, m, a, b;
		cin >> n >> m >> a >> b;

		if (n*a != m*b) {
			cout << "NO" << endl;
			continue;
		}

		int col_sum[m];
		for (int i = 0; i < m; i++) {
			if (i < a)
				col_sum[i] = n;
			else
				col_sum[i] = 0;
		}

		string res[n];
		for (int i = 0; i < n; i++) {
			res[i] = string(a, '1') + string(m-a, '0');
		}

		for (int col = 0; col < m; col++) {
			int row = 0;

			for (int row = 0; row < n && col_sum[col] != b; row++) {
				if (col_sum[col] > b) {
					// Need to lower col_sum, find first zero to the right
					int j;
					for (j = col+1; j < m; j++) {
						if (res[row][j] == '0')
							break;
					}

					if (j < m) {
						// swap 1 and 0
						res[row][col] = '0'; col_sum[col]--;
						res[row][j] = '1'; col_sum[j]++; 
					}

				} else {
					// Need to increase col_sum, find first one to the right
					int j;
					for (j = col+1; j < m; j++) {
						if (res[row][j] == '1')
							break;
					}

					if (j < m) {
						// swap 0 and 1
						res[row][col] = '1'; col_sum[col]++;
						res[row][j] = '0'; col_sum[j]--;						
					}
				}
			}
		}

		cout << "YES" << endl;
		printRes(res, n);
	}

	return 0;
}