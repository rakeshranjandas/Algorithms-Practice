#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void fibSeq(int a[], int n) {

	unordered_set<int> fib;

	int f_a = 1, f_b = 1, f_c;
	fib.insert(0);
	fib.insert(1);

	while (f_b <= 1000) {
		f_c = f_a + f_b;
		f_a = f_b;
		f_b = f_c;
		fib.insert(f_b);
	}

	for (int i = 0; i < n; i++)
		if (fib.find(a[i]) != fib.end())
			cout << a[i] << " ";
	cout << endl;
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

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		fibSeq(a, n);
	}

	return 0;
}