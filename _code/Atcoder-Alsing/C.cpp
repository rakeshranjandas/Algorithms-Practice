#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

#define N 10001

int f(int x, int y, int z) {
	return x*x + y*y + z*z + x*y + y*z + z*x;
}

int main() {

	IOS

	int n;
	cin >> n;

	int a[N] = {0};

	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			for (int k = 1; k <= 100; k++) {
				int val = f(i, j, k);
				if (val < N)
					a[val]++;
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << a[i] << endl;

	return 0;
}