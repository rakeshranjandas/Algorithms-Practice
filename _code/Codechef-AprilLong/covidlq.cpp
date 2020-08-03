#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;
#define ll long long int

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int last_one = -1;
		string ans = "YES";

		for (int i = 0; i < n; i++) {
			if (a[i] == 1) {
				if (last_one == -1)
					last_one = i;

				else if (i - last_one < 6) {
					ans = "NO";
					break;

				} else
					last_one = i;
			}
		}

		cout << ans << endl;
	}

	return 0;
}