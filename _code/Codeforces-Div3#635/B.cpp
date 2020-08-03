#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		if (((n/2) % 2) == 1) {
			cout << "NO" << endl;
			continue;
		}

		cout << "YES" << endl;
		vector<int> v;

		int sum = 0;
		for (int i = 1; i <= n/2; i++) {
			sum += 2*i;
			v.push_back(2*i);
		}

		for (int i = 0; i < n/2-1; i++) {
			sum -= v[i]-1;
			v.push_back(v[i]-1);
		}

		v.push_back(sum);

		for (int x: v)
			cout << x << " ";

		cout << endl;
	}

	return 0;
}