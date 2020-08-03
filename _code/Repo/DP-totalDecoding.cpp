#include<iostream>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

int totalWays(string s, int n) {

	if(n == 0)
		return 1;

	int ways = 0, i = n-1;
	int num = s[i]-'0';
	
	if (num > 0)
		ways += totalWays(s, i);

 	if (i > 0 && s[i-1]-'0' > 0) {
		num += (s[i-1]-'0') * 10;

		if (num <= 26) {
			ways += totalWays(s, i-1);
		}
	}

	return ways;
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
		cin >> n;

		string s;
		cin >> s;

		cout << totalWays(s, n) << endl;
	}

	return 0;
}