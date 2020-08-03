#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int gcd(int a, int b) {
	if (b == 0)
		return a;

	return gcd(b, a%b);
}

int main() {

	IOS

	int n;
	cin >> n;

	ll sum = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				sum += gcd(i, gcd(j, k));

	cout << sum << endl;

	return 0;
}