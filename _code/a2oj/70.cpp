#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	string a, b;
	cin >> a >> b;

	vector<int> v;

	bool same = false;

	if (a.size() == b.size()) {
		for (int i = 0; i < a.size(); i++)
			if (a[i] != b[i])
				v.push_back(i);

		if (v.size() == 2) {
			if (a[v[0]] == b[v[1]] && a[v[1]] == b[v[0]])
				same = true;
		}
	}

	cout << (same ? "YES" : "NO");

	return 0;
}