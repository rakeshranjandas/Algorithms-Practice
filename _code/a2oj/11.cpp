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

	int a[m+1] = {0};
	for (int i = 2; i <= n; i++) {
		if (a[i] == 1)
			continue;

		for (int k = 2; i*k <= m; k++)
			a[i*k] = 1;
	}

	bool found = false;
	int mm;

	for (int i = n+1; i <= m; i++) {
		if (a[i] == 0) {
			mm = i;
			found = true;
			break;
		}
	}

	if (found && mm == m)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}