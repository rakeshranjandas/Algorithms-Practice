#include<iostream>
#include<numeric>
#include<algorithm>
using namespace std;

int main() {

	// #ifndef ONLINE_JUDGE
	// 	freopen("../input.txt", "r", stdin);
	// 	freopen("../output.txt", "w", stdout);
	// 	#else
	// #endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int i = 0, j = n-1;
		bool r = true;

		while (i <= j) {

			if (a[i] > 7 || a[i] < 0) {
				r = false;
				break;
			}

			if (a[i] != a[j]) {
				r = false;
				break;
			}

			int diff = (a[i]-a[i-1]);
			if (i > 0 && (diff < 0 || diff > 1)) {
				r = false;
				break;
			}

			i++;
			j--;
		}

		cout << (r ? "yes" : "no") << endl;
	}

	return 0;
}