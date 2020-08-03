#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int y, k, n;
	cin >> y >> k >> n;

	vector<int> v;

	int first = (y/k + 1) * k;

	if (first > n)
		cout << -1;

	else
		for (int i = first; i <= n; i+=k)
			cout << i-y << " ";



	return 0;
}