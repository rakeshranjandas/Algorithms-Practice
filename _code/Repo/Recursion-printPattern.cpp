#include<iostream>
using namespace std;

void printPattern(int n, int start, bool osc_down) {

	cout << n << " ";

	if (n == start && !osc_down)
		return;

	int next;

	if (osc_down) {
		next = n-5;

		if (next < 0)
			osc_down = false;

	} else 
		next = n+5;


	printPattern(next, start, osc_down);
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

		printPattern(n, n, true);
		cout << endl;
	}

	return 0;
}