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

	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int coin[3] = {0};
	string res = "YES";

	for (int i = 0; i < n; i++) {

		if (a[i] == 100)
			coin[2]++;

		else if (a[i] == 50)
			coin[1]++;

		else
			coin[0]++;

		int give_back = a[i] - 25;

		// deb(give_back);

		while (give_back >= 100 && coin[2]) {
			give_back -= 100;
			coin[2]--;
		}

		while (give_back >= 50 && coin[1]) {
			give_back -= 50;
			coin[1]--;
		}

		while (give_back >= 25 && coin[0]) {
			give_back -= 25;
			coin[0]--;
		}

		if (give_back > 0) {
			res = "NO";
			break;
		}
	}

	cout << res;

	return 0;
}