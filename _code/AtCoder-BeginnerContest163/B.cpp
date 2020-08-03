#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int n, m;
	cin >> n >> m;

	int sum = 0, a;
	for (int i = 0; i < m; i++) {
		cin >> a;
		sum += a;
	}

	int hangout = n-sum;
	cout << (hangout < 0 ? -1 : hangout) << endl;

	return 0;
}