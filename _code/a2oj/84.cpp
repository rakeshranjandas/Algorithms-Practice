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

	int sum1 = 0, sum2 = 0, x1, x2;
	int eo = 0;

	for (int i = 0; i < n; i++) {
		cin >> x1 >> x2;
		sum1 += x1;
		sum2 += x2;

		if ((x1%2 == 0 && x2%2 == 1) || (x1%2 == 1 && x2%2 == 0))
			eo++;
	}

	if (sum1%2 == 0  && sum2%2 == 0)
		cout << 0;

	else if (sum1%2 == 0 && sum2%2 == 1)
		cout << -1;

	else if (sum1%2 == 1 && sum2%2 == 0)
		cout << -1;

	else if (eo)
		cout << 1;

	else
		cout << -1;

	return 0;
}