#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	long long int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a+n);
	long long int sum = 0;

	for (int i = 0; i < n-k; i++)
		sum += a[i];

	cout << sum << endl;


	return 0;
}