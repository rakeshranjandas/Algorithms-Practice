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

	int l_0 = 0, r_1 = 0, l_1 = 0, r_0 = 0, ip1, ip2;

	for (int i = 0; i < n; i++) {
		cin >> ip1 >> ip2;

		if (ip1 == 0)
			l_0++;
		else
			l_1++;

		if (ip2 == 0)
			r_0++;
		else
			r_1++;
	}

	int cost = min(l_1, l_0) + min(r_1, r_0);
	cout << cost;
	return 0;
}







