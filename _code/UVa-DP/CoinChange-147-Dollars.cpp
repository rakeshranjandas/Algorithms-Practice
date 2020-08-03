#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;
#define N 11
#define V 30001
// #define V 190

int coin[N] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
ll dp[V];

void init() {
	for (int i = 0; i < N; i++) {
		if (coin[i] < V)
			dp[coin[i]]++;

		for (int j = 1; j < V; j++)
			if (dp[j] && (j + coin[i]) < V)
				dp[j + coin[i]] += dp[j];
	}

	// for (int k = 0; k < V; k++)
	// 	cout << "(" << k << ")" << dp[k] << " ";
	// cout << endl;
}

int main() {

	init();

	double n;

	while (cin >> n && n != 0) {

		cout << std::setw(6) << std::fixed << std::setprecision(2) << n
			<< std::setw(17) << dp[(int)rint(n*100)] << endl;
	}

	return 0;
}