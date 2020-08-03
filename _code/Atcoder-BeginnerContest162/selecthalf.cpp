#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

#define N 200001
ll ans = 0;
ll a[N];
int choose, n;
unordered_map<int, unordered_map<int, ll>> dp;
unordered_map<int, unordered_map<int, bool>> can_find;

bool haveProcessed(int cur, int more) {
	return can_find.find(cur) != can_find.end() && can_find[cur].find(more) != can_find[cur].end();
}

bool calc(int cur, int more, ll *max_val) {

	if (more == 0) {
		*max_val = 0;
		return true;
	}

	int rest_arr_size = n - cur;

	if (more > (rest_arr_size - rest_arr_size/2))
		return false;

	if (cur >= n) {
		return false;
	}

	if (haveProcessed(cur, more)) {
		*max_val = dp[cur][more];
		return can_find[cur][more];
	}

	ll val_with_rest, val_with = LONG_MIN;
	ll val_without_rest, val_without = LONG_MIN;

	bool can_find_with = calc(cur + 2, more - 1, &val_with_rest);
	if (can_find_with) {
		val_with = a[cur] + val_with_rest;
	}

	bool can_find_without = calc(cur + 1, more, &val_without_rest);
	if (can_find_without) {
		val_without = val_without_rest;
	}

	*max_val = max(val_with, val_without);

	can_find[cur][more] = can_find_with || can_find_without;
	dp[cur][more] = *max_val;

	return can_find[cur][more];
}

int main() {

	IOS

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	choose = n/2;

	ll max_val = 0;
	calc(0, choose, &max_val);

	cout << max_val;

	return 0;
}