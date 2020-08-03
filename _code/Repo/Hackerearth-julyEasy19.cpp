#include<iostream>
using namespace std;

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	int n, m, k;
	cin >> n >> m >> k;

	int sum_of_k_last = (k * (2 *m + (k-1) * (-1))) / 2;
	cout << sum_of_k_last << "-<" << endl;
	int ans = 0;

	ans += (n/sum_of_k_last) * k;
	cout << "ans " << ans << endl;

	n %= sum_of_k_last;
	cout << "n " << n << endl;

	int i, steps = 0;

	for (i = m; i > 0 && n >= 0; i--) {
		n -= i;
		steps++;
	}

	cout << "steps " << steps << endl;
	ans += steps;

	cout << ans << endl;
	return 0;
}