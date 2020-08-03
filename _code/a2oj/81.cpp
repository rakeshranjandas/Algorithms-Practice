#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

#define M (1<<30)

int countDivisors(int n) {
	if (n == 1)
		return 1;

	int c = 2;
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) {
			if (i*i == n)
				c++;
			else
				c+=2;
		}
	}

	return c;
}

int main() {

	IOS

	int a, b, c;
	cin >> a >> b >> c;

	ll sum_div = 0;

	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			for (int k = 1; k <= c; k++) {
				sum_div = (sum_div + countDivisors(i*j*k)) % M;
			}
		}
	}

	cout << sum_div;

	return 0;
}