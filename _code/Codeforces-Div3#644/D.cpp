#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

vector<int> findAllDiv(int n) {
	vector<int> v;

	for (int i = 1; i*i <= n; i++) {
		if (n%i == 0) {
			if (n/i == i)
				v.push_back(i);
			else {
				v.push_back(i);
				v.push_back(n/i);
			}
		}
	}

	sort(v.begin(), v.end());

	return v;
}

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		if (n == k) {
			cout << 1 << endl;
			continue;
		}

		vector<int> v = findAllDiv(n);
		auto it = upper_bound(v.begin(), v.end(), k);
		it--;

		cout << (n / *it) << endl;

	}

	return 0;
}