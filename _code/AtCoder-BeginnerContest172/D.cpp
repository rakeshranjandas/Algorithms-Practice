#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

#define N 10000001
// #define N 200

int div_count[N];

void init() {
	div_count[1] = 1;

	for (int i = 2; i < N; i++)
		div_count[i] = 2;

	for (int i = 2; i*i < N; i++) {
		
		for (int j = i*i; j < N; j += i) {
			if (j == i*i)
				div_count[j]++;
			else
				div_count[j] += 2;
		}
	}

	// for (int i = 0; i < N; i++)
	// 	cout << "(" << i << ")" << div_count[i] << " ";
	// cout << endl;
}

ll solve(int n) {
	init();

	ll ans = 0;
	for (int i = 1; i <= n; i++)
		ans += (ll)i * (ll)div_count[i];

	return ans;
}

int main() {

	IOS

	int n;
	cin >> n;

	cout << solve(n);

	return 0;
}