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

	int c = 0, entered, exited, cap = 0;

	for (int i = 0; i < n; i++) {
		cin >> exited >> entered;
		c += entered - exited;
		cap = max(c, cap);
	}

	cout << cap;

	return 0;
}