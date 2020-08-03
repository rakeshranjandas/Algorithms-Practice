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

		int coin[n+1];
		int total_amount = 0;

		for (int i = 1; i <= n; i++) {
			cin >> coin[i];
			total_amount += coin[i];
		}

		int mid_val = total_amount / 2;
		int v[mid_val+1] = {0};

		// deb(total_amount);

		for (int i = 1; i <= n; i++) {
			if (coin[i] > mid_val)
				continue;

			if (!v[coin[i]])
				v[coin[i]] = i;

			for (int j = 1; j <= mid_val; j++) {
				if (v[j] && v[j] != i && j+coin[i] <= mid_val && v[j+coin[i]] == 0)
					v[j+coin[i]] = i;
			}

			// for (int k = 0; k <= mid_val; k++)
			// 	cout << "(" << k << ")" << v[k] << " ";
			// cout << endl;
		}

		int half_amount = 0;
		for (int i = mid_val; i >= 1; i--) {
			if (v[i]) {
				half_amount = i;
				break;
			}
		}

		cout << abs(half_amount - (total_amount - half_amount)) << endl;
	}

	return 0;
}