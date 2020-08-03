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

	if (n%2 == 1)
		cout << -1;

	else {
		for (int i = 1; i <= n; i+=2) {
			cout << i+1 << " " << i << " ";
		}
	}

	return 0;
}