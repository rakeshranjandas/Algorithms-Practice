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

	int c100 = 0, c200 = 0, sum = 0, x;

	for (int i = 0; i < n; i++) {
		cin >> x;

		if (x == 100)
			c100++;
		else
			c200++;

		sum += x;
	}

	bool can = false;

	for (int i = 0; i <= c100 && !can; i++) {
		for (int j = 0; j <= c200 && !can; j++) {
			int asum = i*100 + j*200;
			int bsum = (c100-i) * 100 + (c200-j) * 200;

			if (asum == sum/2 && asum == bsum)
				can = true;
		}
	}

	cout << (can ? "YES" : "NO");

	return 0;
}