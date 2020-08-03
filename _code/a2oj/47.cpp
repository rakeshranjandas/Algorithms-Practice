#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;
#define N 1001

int main() {

	IOS

	ll n, m;
	cin >> n >> m;

	int c = 0;

	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			if (a*a + b == n && a + b*b == m)
				c++;
		}
	}

	cout << c;

	return 0;
}