#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int sq(int n) {
	return n*n;
}

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << sq(max(2*(min(a, b)), max(a, b))) << endl;
	}

	return 0;
}