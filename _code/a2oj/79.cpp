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

	int fh[n], sh[n], xi = 0;

	for (int i = 0; i < n; i++)
		fh[i] = s[xi++] - '0';

	for (int i = 0; i < n; i++)
		sh[i] = s[xi++] - '0';

	sort(fh, fh+n);
	sort(sh, sh+n);

	bool unlucky = true;

	// for (int i = 0; i < n; i++)
	// 	cout << fh[i] << " ";
	// cout << endl;


	// for (int i = 0; i < n; i++)
	// 	cout << sh[i] << " ";
	// cout << endl;


	if (fh[0] > sh[0]) {
		
		for (int i = 0; i < n; i++) {
			if (fh[i] <= sh[i]) {
				unlucky = false;
				break;
			}
		}

	} else if (fh[0] < sh[0]) {

		for (int i = 0; i < n; i++) {
			if (fh[i] >= sh[i]) {
				unlucky = false;
				break;
			}
		}

	} else
		unlucky = false;


	cout << (unlucky ? "YES" : "NO");

	return 0;
}