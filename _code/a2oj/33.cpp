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
	
	pair<int, int> a[n];
	map<int, vector<int>> mpx, mpy;

	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		mpx[a[i].first].push_back(i);
		mpy[a[i].second].push_back(i);
	}

	int c = 0;

	for (int i = 0; i < n; i++) {
		// cout << a[i].first << " " << a[i].second << endl;

		// search for left neigbour and right neighbour
		auto same_y = mpy[a[i].second];
		bool left_neigh_found = false, right_neigh_found = false;

		for (int ind: same_y) {
			if (left_neigh_found && right_neigh_found)
				break;

			if (a[ind].first < a[i].first)
				left_neigh_found = true;

			else if (a[ind].first > a[i].first)
				right_neigh_found = true;
		}

		if (!left_neigh_found || !right_neigh_found)
			continue;

		// search for up neigbour and down neighbour
		auto same_x = mpx[a[i].first];
		bool up_neigh_found = false, down_neigh_found = false;

		for (int ind: same_x) {
			if (up_neigh_found && down_neigh_found)
				break;

			if (a[ind].second < a[i].second)
				down_neigh_found = true;

			else if (a[ind].second > a[i].second)
				up_neigh_found = true;
		}

		if (!up_neigh_found || !down_neigh_found)
			continue;

		c++;
	}

	cout << c;

	return 0;
}