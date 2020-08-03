#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int x, n;
	cin >> x >> n;

	unordered_set<int> s;
	int ip;

	for (int i = 0; i < n; i++) {
		cin >> ip;
		s.insert(ip);
	}

	for (int i = 0; ; i++) {

		if (s.find(x-i) == s.end()) {
			cout << x-i;
			break;
		}

		if (s.find(x+i) == s.end()) {
			cout << x+i;
			break;
		}
	}

	return 0;
}