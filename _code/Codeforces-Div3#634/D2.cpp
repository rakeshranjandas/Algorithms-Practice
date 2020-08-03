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
		string s[9];
		for (int i = 0; i < 9; i++) {
			cin >> s[i];

			for (int j = 0; j < 9; j++)
				if (s[i][j] == '5')
					s[i][j] = '6';

			cout << s[i] << endl;
		}
	}

	return 0;
}