#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int longestNonDec(vector<int> v) {

	int n = v.size();
	int dp[n];
	for (int i = 0; i < n; i++)
		dp[i] = 1;

	int max_len = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[j] >= v[i]) {
				dp[i] = max(dp[j]+1, dp[i]);
				max_len = max(max_len, dp[i]);
			}
		}
	}

	return max_len;
}

int main() {

	IOS

	int ip, t = 1;
	bool flag = false;
	vector<int> v;

	while (1) {
	
		cin >> ip;

		if (ip == -1 && flag)
			break;

		if (ip == -1) {

			if (t > 1)
				cout << endl;

			flag = true;

			cout << "Test #" << t++ << ":\n  maximum possible interceptions: ";
			cout << longestNonDec(v) << endl;

			v.clear();
			continue;
		}

		flag = false;

		v.push_back(ip);

	}

	return 0;
}