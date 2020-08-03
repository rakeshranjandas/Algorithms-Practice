#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

#define N 6
#define V 1001

int coin[] = {5, 10, 20, 50, 100, 200};
int dp[V];

int a[N];
double amount;
int dp_a[N+1][V];

void init() {
	for (int i = 0; i < N; i++) {

		if (coin[i] >= V)
			continue;

		if (dp[coin[i]])
			dp[coin[i]] = min(dp[coin[i]], 1);
		else
			dp[coin[i]] = 1;

		for (int j = 1; j < V; j++) {
			if (dp[j] && (j+coin[i]) < V) {

				if (dp[j+coin[i]])
					dp[j+coin[i]] = min(dp[j+coin[i]], dp[j]+1);
				else
					dp[j+coin[i]] = dp[j]+1;
			}			
		}
	}


	// for (int i = 1; i < V; i++)
	// 	cout << "(" << i << ")" << dp[i] << "\t";
	// cout << endl;
}

bool inputAllZeros() {
	for (int i = 0; i < N; i++)
		if (a[i] > 0)
			return false;

	return true;
}

void findPossibleAmount() {
	memset(dp_a, -1, sizeof(dp_a));
	dp_a[0][0] = 0;

	int coin_i;

	// for (int i = 0; i < V; i++)
	// 	cout << "(" << i << ")" << dp_a[0][i] << " ";
	// cout << endl;

	for (int i = 1; i <= N; i++) {
		coin_i = i-1;

		for (int j = 0; j < V; j++) {

			if (dp_a[i-1][j] != -1) {

				if (dp_a[i][j] == -1)
					dp_a[i][j] = dp_a[i-1][j];
				else
					dp_a[i][j] = min(dp_a[i][j], dp_a[i-1][j]);

				for (int k = 1; k <= a[coin_i]; k++) {

					int pos = j + k*coin[coin_i];

					if (pos >= V)
						break;

					if (dp_a[i][pos] == -1)
						dp_a[i][pos] = dp_a[i-1][j] + k;

					else
						dp_a[i][pos] = min(dp_a[i][pos], dp_a[i-1][j] + k);

					// deb(i);
					// deb(pos);
				}
			}
		}

		// for (int ai = 0; ai < V; ai++)
		// 	cout << "(" << ai << ")" << dp_a[i][ai] << " ";
		// cout << endl;
	}
}

int findMinAllPossibleExchange() {

	int pay = (int)rint(amount*100);
	// deb(pay);
	int min_ex = INT_MAX;

	for (int i = pay; i < V; i++) {
		if (dp_a[N][i] == -1)
			continue;

		min_ex = min(min_ex, dp_a[N][i] + dp[i-pay]);

		// deb(min_ex);
		// deb(i);
	}

	return min_ex;
}

int findMinExchange() {
	findPossibleAmount();
	return findMinAllPossibleExchange();
}

int main() {

	init();

	while (true) {
		for (int i = 0; i < N; i++)
			cin >> a[i];

		if (inputAllZeros())
			break;

		cin >> amount;

		cout << setw(3) << findMinExchange() << endl;
	}

	return 0;
}