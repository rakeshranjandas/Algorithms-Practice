#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

#define N 500001
ll memo[N];

void init() {
	ll s = 0, p = 1, m = 1;

	for (int i = 3; i < N; i += 2) {
		memo[i] = s + m * (p * 4 + 4);
		s = memo[i];

		m++;
		p += 2;
	}
}

int main() {

	IOS

	init();

	int t;
	cin >> t;

	while (t--) {
		ll n;
		cin >> n;

		cout << memo[n] << endl;
	}

	return 0;
}