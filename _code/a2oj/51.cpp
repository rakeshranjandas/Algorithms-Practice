#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int n, a, b;
	cin >> n >> a >> b;

	int c = 0;

	for (int i = 1; i <= n; i++) {
		int in_front = i-1;
		int in_behind = n-i;

		if (in_front >= a && in_behind <= b)
			c++;
	}

	cout << c;

	return 0;
}