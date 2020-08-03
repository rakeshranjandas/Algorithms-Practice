#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

void printVector(vector<int> &v) {
	for (auto x: v)
		cout << x << " ";
	cout << endl;
}

int main() {

	IOS

	int n, k, c;
	cin >> n >> k >> c;

	string s;
	cin >> s;

	vector<int> earliest, latest;

	for (int i = 0; i < n && earliest.size() < k; i++) {
		if (s[i] == 'o') {
			earliest.push_back(i);
			i += c;
		}
	}

	if (earliest.size() == k) {

		for (int i = n-1; i >= 0 && latest.size() < k; i--) {
			if (s[i] == 'o') {
				latest.push_back(i);
				i -= c;
			}
		}

		if (latest.size() == k) {
			reverse(latest.begin(), latest.end());

			for (int i = 0; i < k; i++)
			if (latest[i] == earliest[i])
				cout << earliest[i]+1 << endl;
		}
	}

	return 0;
}