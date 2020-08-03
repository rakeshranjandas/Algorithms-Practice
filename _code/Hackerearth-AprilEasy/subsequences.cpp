#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;
#define N 100001
int ans[N];

typedef long long int ll;

bool hasLeftmostDigitOdd(int n) {
	int lg10 = (int) log10(n);
	int left_most_digit = n / pow(10, lg10);
	return left_most_digit & 1;
}

void init() {
	int k = 1, i = 1;
	while (k < N) {

		if (hasLeftmostDigitOdd(i)) {
			ans[k] = i;
			k++;
		}

		i++;
	}
}

int main() {

	IOS

	init();

	int t;
	cin >> t;

	while (t--) {
		int k;
		cin >> k;
		cout << "1 " << ans[k] << endl;
	}

	return 0;
}