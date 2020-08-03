#include<iostream>
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
		int n, s;
		cin >> n >> s;

		string str = "";

		for (int i = 0; i < n; i++) {
			if (s >= 9) {
				str += '9';
				s -= 9;

			} else {
				str += (s + '0');
				s -= s;
			}
		}

		cout << (s > 0 ? "-1" : str) << endl;
	}

	return 0;
}