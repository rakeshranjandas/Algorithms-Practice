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

	string s;
	cin >> s;

	char prev = s[0];
	int cnt = 0;

	for (int i = 1; i < n; i++) {
		if (s[i] == prev)
			cnt++;

		else
			prev = s[i];
	}

	cout << cnt;

	return 0;
}