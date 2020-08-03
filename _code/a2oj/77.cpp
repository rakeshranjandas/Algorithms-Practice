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

	int x, sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		sum += x;
	}

	int c;
	if (sum % n == 0)
		c = n;
	else
		c = n-1;

	cout << c;

	return 0;
}