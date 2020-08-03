#include<iostream>
#include<cmath>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

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

		string s;
		int k;

		cin >> s >> k;

		int len = s.length();

		if (ceil((double)len/k) >= k && (len%k == 0 || len%k == k-1)) {

			for (int i = 0; i < len; i++) {
				cout << s[i];

				if (i%k == k-1 && i != len-1)
					cout << "-";
			}

		} else {
			cout << "-1";
		}

		cout << endl;
	}

	return 0;
}