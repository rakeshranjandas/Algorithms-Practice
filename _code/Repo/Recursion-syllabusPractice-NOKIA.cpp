#include<iostream>
#include<limits.h>
using namespace std;

int part(int l, int r, int m) {

	if (l == r-1)
		return m-1;

	int rope_unused = INT_MAX, rope_used = r-l;

	int rope_left = m-r+l;

	for (int i = l+1, i < r; i++) {
		rope_unused = min(rope_unused, part(l, i, ) + part(i, r));
	}

	return rope;
}

int nokia(int n, int m) {

	part(0, n+1, m);
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
		int n, m;
		cin >> n >> m;

		cout << nokia(n, m) << endl;
	}

	return 0;
}