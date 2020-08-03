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
	
	int x, c = 0;

	for (int i = 1; i <= n; i++) {
		cin >> x;

		if (i%2 == 1 && x%2 == 1)
			c++;
	}

	cout << c;

	return 0;
}