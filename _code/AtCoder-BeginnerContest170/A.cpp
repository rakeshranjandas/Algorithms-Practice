#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int res, ip;
	for (int i = 0; i < 5; i++) {
		cin >> ip;
		if (ip == 0)
			res = i+1;
	}

	cout << res;

	return 0;
}