#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

void solve() {
	int x, y;
	cin >> x >> y;

	// if both are even - impossible
	// if both are odd - impossible
	// one has to be even, another odd

	if ((abs(x) + abs(y)) % 2 == 0) {
		cout << "IMPOSSIBLE";
		return;
	}


	

}

int main() {

	IOS

	int t;
	cin >> t;

	for (int t_i = 1; t_i <= t; t_i++) {
		cout << "Case #" << t_i << ": ";
		solve();
		cout << endl;
	}

	return 0;
}