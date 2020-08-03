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

	int a[m];
	for (int i = 0; i < m; i++)
		cin >> a[i];

	priority_queue<int, vector<int>, greater<int>> pq_min;
	priority_queue<int> pq_max;

	int mx = 0, mn = 0;

	for (int i = 0; i < m; i++) {
		pq_min.push(a[i]);
		pq_max.push(a[i]);
	}

	for (int i = 0; i < n; i++) {
		int mx_top = pq_max.top();
		pq_max.pop();

		mx += mx_top;

		if (mx_top-1 > 0)
			pq_max.push(--mx_top);


		int mn_top = pq_min.top();
		pq_min.pop();

		mn += mn_top;

		if (mn_top-1 > 0)
			pq_min.push(--mn_top);
	}

	cout << mx << " " << mn;


	return 0;
}