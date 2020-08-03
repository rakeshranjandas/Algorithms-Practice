#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int n;
	cin >> n;
	
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int si = 0;
	bool dec = false;

	for (int i = 0; i < n-1; i++) {
		if (a[i] > a[i+1]) {
			si = i;
			dec = true;
			break;
		}
	}

	if (!dec)
		cout << "yes\n1 1";

	else {
		int ei = n;

		for (int i = si; i < n-1; i++) {
			if (a[i] < a[i+1]) {
				ei = i+1;
				break;
			}
		}

		// copy
		int b[n];
		for (int i = 0; i <n; i++)
			b[i] = a[i];

		// deb(si);
		// deb(ei);

		reverse(b+si, b+ei);
		sort(a, a+n);

		bool same = true;

		for (int i = 0; i < n; i++) {
			if (a[i] != b[i]) {
				same = false;
				break;
			}
		}

		if (same)
			cout << "yes" << endl << si+1 << " " << ei;

		else
			cout << "no";
	}


	return 0;
}