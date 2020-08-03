#include<iostream>
using namespace std;

#define MOD 1000000007

bool allDigitsLessThanK(string s, long long int k) {

	for (auto x: s)
		if (x-'0' >= k)
			return false;
		

	return true;
}

long long int ways(string s, long long int k, int n, int dp[]) {

	dp[0] = 1;

	long long int num, tens;
	int now;

	for (int i = 1; i < n; i++) {

		now = i-1;

		// cout << now << endl;

		for (
			num = (s[i]-'0'), tens = 1;
			now >= -1 && num < k;
			tens *= 10, num += (s[now]-'0')*tens, --now
		) {

			// cout << "num " << num << endl;
			dp[i] = (dp[i] + ((now == -1) ? 1 : dp[now])) %MOD;
		}
	}

	// for (int i = 0; i < n; i++)
	// 	cout << dp[i] << " ";
	// cout << endl;

	return dp[n-1];
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

	while (t--) {
		int n;
		long long int k;

		cin >> n >> k;

		string s;
		cin >> s;

		// Check if all individual digits are less than k
		// if not the string cannot be partitioned
		if (!allDigitsLessThanK(s, k)) {
			cout << 0 << endl;
			continue;
		}

		int dp[n] = {0};

		cout << ways(s, k, n, dp) << endl;
	}

	return 0;
}