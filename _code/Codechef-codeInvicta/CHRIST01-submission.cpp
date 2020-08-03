#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILE_WR freopen("../input.txt", "r", stdin);\
	freopen("../output.txt", "w", stdout);
#define deb(x)	cout << #x << " " << x << endl;
#define ll long long int

const int mx = 1000000;
const int mod = 1e9 + 7;
void add_self (int & a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

void sub_self (int & a, int b) {
	a -= b;
	if (a < 0) a += mod;
}

int mul (int a, int b) {
	return (ll) a * b % mod;
}

int power (int a, int k) {
	int ans = 1;
	while (k > 0) {
		if (k & 1) ans = mul (ans, a);
		a = mul (a, a);
		k >>= 1;
	}
	return ans;
}

int inverse (int n) {
	return power (n, mod - 2);
}

int fact[mx];

void solve() {
	int n, k;
	cin >> n >> k;
	int answer = 0;
	int current = n;
	int sign = 1;
	for (int m = 1; m <= n; m++) {
		current = mul (fact[n], inverse (mul (fact[m], fact[n - m])));
		deb(current);
		current = mul (current, fact[m + (n - m) * k]);
		deb(current);
		deb(inverse (power (fact[k], n - m)));

		current = mul (current, inverse (power (fact[k], n - m)));
		deb(current);


		if (sign == 1) {
			add_self (answer, current);
		} else {
			sub_self (answer, current);
		}
		//cout << current << endl;
		// add_self (answer, mul (sign, current));
		sign = -sign;
	}
	cout << answer << endl;
}

int main() {
	FILE_WR
	ios_base::sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	fact[0] = 1;
	for (int i = 1; i < mx; i++) {
		fact[i] = mul (fact[i - 1], i);
	}
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
	return 0;
}

