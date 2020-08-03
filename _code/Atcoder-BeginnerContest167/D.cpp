#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

int main() {

	IOS

	int n;
	ll k;
	cin >> n >> k;

	int a[n+1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	// for (int i = 0; i <= n; i++)
	// 	cout << a[i] << " ";
	// cout << endl;

	int vis[n+1], rem_town[n+1] = {0};
	memset(vis, -1, sizeof(vis));

	int cur = 1, step = 0;
	while (vis[cur] == -1) {
		vis[cur] = step;
		rem_town[step] = cur;
		step++;
		cur = a[cur];
	}

	// for (int i = 0; i <= n; i++)
	// 	cout << vis[i] << " ";
	// cout << endl;

	// for (int i = 0; i <= n; i++)
	// 	cout << rem_town[i] << " ";
	// cout << endl;

	int offset = vis[cur], cycle_len = step - vis[cur], rem;

	// deb(step);
	// deb(vis[cur]);
	// deb(cycle_len);

	if (k < offset) {
		cout << rem_town[k] << endl;

	} else {
		k -= (ll)offset;
		k = k % (ll)cycle_len;
		k += (ll)offset;

		// deb(k);
		// deb(offset);
		cout << rem_town[(int)k] << endl;
	}



	return 0;
}