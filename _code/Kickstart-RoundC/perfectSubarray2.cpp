#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

vector<int> sq_v;

void init() {
	int i = 0;
	while (true) {
		int sq = i * i;

		if (sq > 10000001)
			break;

		sq_v.push_back(sq);

		i++;
	}
}

// bool isPerfectSquare(int num) {
// 	if (num < 0)
// 		return false;

// 	return sq_set.find(num) != sq_set.end();

// 	// deb(num);
// 	// deb(sqrt(num));
// 	// deb((double)num)

// 	// int sq = (int)rint(sqrt(num));

// 	// deb((sq*sq  == (double) num));

// 	// return sq * sq == num;
// }

void solve() {

	init();

	int n;
	cin >> n;

	int a[n];

	int acc[n+1];
	acc[0] = 0;

	ll sum_pos = 0, sum_neg = 0;
	map<int, set<int>> mpi;
	mpi[0].insert(0);


	for (int i = 0; i < n; i++) {
		cin >> a[i];
		acc[i+1] = acc[i] + a[i];

		if (a[i] > 0)
			sum_pos += a[i];
		else
			sum_neg += a[i];

		mpi[acc[i+1]].insert(i+1);
	}

	// for (int i = 0; i < n; i++) {
	// 	acc[i+1] = acc[i] + a[i];

	// 	if (a[i] > 0)
	// 		sum_pos += a[i];
	// 	else
	// 		sum_neg += a[i];

	// 	mpi[acc[i+1]].insert(i+1);
	// }

	int c = 0;
	auto start_from_it = lower_bound(sq_v.begin(), sq_v.end(), sum_pos - sum_neg);

	// deb(*start_from_it);

	// for (auto x: mpi) {
	// 	cout << x.first << " - ";
	// 	for (auto xx: x.second)
	// 		cout << xx << " ";
	// 	cout << endl;
	// }

	// deb(sum_pos);
	// deb(sum_neg);

	for (int i = 0; i <= n; i++) {
		
		auto it = start_from_it;

		while (true) {

			cout << acc[i] << " searching " << *it + acc[i] << endl;

			if (mpi.find(*it + acc[i]) != mpi.end()) {

				auto it1 = mpi[*it + acc[i]].lower_bound(i+1);
				c += distance(it1, mpi[*it + acc[i]].end());

				cout << "found. Added " << distance(it1, mpi[*it + acc[i]].end()) << endl; 
			}

			if (*it == 0)
				break;
			it--;
		}
	}

	cout << c;
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