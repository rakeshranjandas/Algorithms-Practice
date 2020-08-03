#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int n, m;
	cin >> n >> m;

	ll moves = 0, ip, last_ip = 1;

	for (int i = 0; i < m; i++) {
		cin >> ip;

		if (ip >= last_ip)
			moves += ip - last_ip;

		else
			moves += (ll)n - last_ip + ip;

		last_ip = ip;
	}

	cout << moves;

	return 0;
}