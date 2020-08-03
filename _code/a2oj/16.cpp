#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int b[4], d;
	cin >> b[0] >> b[1] >> b[2] >> b[3] >> d;

	bool a[d+1] = {0};
	for (int i = 0; i < 4; i++) {
		for (int k = 1; b[i]*k <= d; k++)
			a[b[i]*k] = true;
	}

	int c = 0;
	for (int i = 1; i <= d; i++) {
		// cout << "(" << i << ")" << a[i] << " ";
		if (a[i])
			c++;
	}

	cout << c;

	return 0;
}