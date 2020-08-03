#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		string s[n];
		for (int i = 0; i < n; i++)
			cin >> s[i];

		bool can = true;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

				if (i == n-1 || j == n-1 || s[i][j] == '0' || (s[i][j] == '1' && (s[i][j+1] == '1' || s[i+1][j] == '1')))
					continue;

				can = false;
				break;
			}

			if (!can)
				break;
		}

		cout << (can ? "YES" : "NO") << endl;
	}

	return 0;
}