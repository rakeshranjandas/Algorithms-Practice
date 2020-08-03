#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;
#define ll long long int

int main() {

	IOS

	int n;
	cin >> n;

	int u, v;
	for (int i = 0; i < n-1; i++)
		cin >> u >> v;

	bool blocked[n];
	for (int i = 0; i < n; i++)
		cin >> blocked[i];

	int max_w = 2, cur_w;
	int start_ind = -1;

	if (!blocked[0])
		start_ind = 0;

	for (int i = 1; i < n; i++) {

		if (!blocked[i] && blocked[i-1])
			start_ind = i-1;

		else if (blocked[i] && !blocked[i-1]) {
			max_w = max(max_w, i-start_ind+1);
			start_ind = -1;
		}
	}

	if (start_ind != -1)
		max_w = max(max_w, n-start_ind);

	cout << max_w << endl;

	return 0;
}