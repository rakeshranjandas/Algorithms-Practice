#include<iostream>
#include <numeric>
using namespace std;

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
		int x, y, k, n;
		cin >> x >> y >> k >> n;

		int required = x - y;
		bool can_buy = false;
		
		int pi, ki;
		for (int i = 0; i < n; i++) {
			cin >> pi >> ki;

			if(!can_buy && ki <= k && pi >= required)
				can_buy = true;
		}
		
		cout << (can_buy ? "LuckyChef" : "UnluckyChef") << endl;
	}

	return 0;
}