#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int a, b, n;
	cin >> a >> b >> n;

	bool can = false;

	for (int i = 0; i <= 9; i++) {
		if ((a*10 + i) % b == 0) {
			a = a*10 + i;
			can = true;
			break;
		}
	}

	if (can) {
		n--;
		cout << a;
		while (n--)
			cout << 0;

	} else
		cout << -1;

	return 0;
}