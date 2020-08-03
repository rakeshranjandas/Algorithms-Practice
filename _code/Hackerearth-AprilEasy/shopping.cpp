#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;
unordered_map<ll, unordered_map<ll, ll>> dp_count;

bool hasProcessed(int i, int j) {
	return dp_count.find(i) != dp_count.end() && dp_count[i].find(j) != dp_count[i].end();
}

ll validWaysUtil(ll a[], int n, int cur, ll x, ll y, int last_bob_i, int last_james_i) {

	if (cur >= n)
		return 1;

	// if (hasProcessed(last_bob_i, last_james_i)) {
	// 	return dp_count[last_bob_i][last_james_i];
	// }

	bool taken_by_bob = last_bob_i == -1|| (a[cur] - a[last_bob_i]) >= x;
	bool taken_by_james = last_james_i == -1 || (a[cur] - a[last_james_i]) >= y;

	ll c = 0;

	if (taken_by_bob)
		c += validWaysUtil(a, n, cur+1, x, y, cur, last_james_i);

	if (taken_by_james)
		c += validWaysUtil(a, n, cur+1, x, y, last_bob_i, cur);

	// dp_count[last_bob_i][last_james_i] = c;

	return c;
} 

ll validWays(ll a[], int n, ll x, ll y) {
	dp_count.clear();
	sort(a, a+n);
	return validWaysUtil(a, n, 0, x, y, -1, -1);
}

int main() {

	IOS

	int n;
	ll x, y;
	cin >> n >> x >> y;

	ll a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << validWays(a, n, x, y) << endl;

	return 0;
}