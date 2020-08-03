#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	char a[4][4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cin >> a[i][j];

	int min_change = 4;

	for (int i = 0; i < 4-1; i++) {
		for (int j = 0; j < 4-1; j++) {
			map<char, int> mp;
			mp[a[i][j]]++;
			mp[a[i+1][j]]++;
			mp[a[i][j+1]]++;
			mp[a[i+1][j+1]]++;

			min_change = min(min_change, min(mp['#'], mp['.']));
		}
	}

	cout << (min_change <= 1 ? "YES" : "NO");

	return 0;
}