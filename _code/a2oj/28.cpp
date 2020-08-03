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

	int ip1, ip2, ip3, c = 0;

	for (int i = 0; i < n; i++) {
		cin >> ip1 >> ip2 >> ip3;

		if (ip1 + ip2 + ip3 >= 2)
			c++;
	}

	cout << c;

	return 0;
}