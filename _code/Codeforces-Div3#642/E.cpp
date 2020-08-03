#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;

typedef long long int ll;

void printMap(unordered_map<int, int> rem_mp) {

	for (auto x: rem_mp) {
		cout << x.first << "-" << x.second << ", ";
	}
	cout << endl;
}

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		string gar;
		cin >> gar;

		int first_one = gar.find("1");
		int last_one = gar.rfind("1");

		if (first_one == string::npos || first_one == last_one) {
			cout << 0 << endl;
			continue;
		}

		deb(first_one);
		deb(last_one);
		unordered_map<int, int> rem_mp_zero, rem_mp_one;
		int total_ones = 0;

		for (int i = first_one; i <= last_one; i++) {
			if (gar[i] == '0')
				rem_mp_zero[i%k]++;
			else {
				rem_mp_one[i%k]++;
				total_ones++;
			}
		}

		printMap(rem_mp_zero);
		printMap(rem_mp_one);
		deb(total_ones);

		int min_flips = INT_MAX;

		for (auto rem: rem_mp_one) {

			int flips_res_to_zero = total_ones - rem.second;
			int flips_req_to_one = rem_mp_zero
		}


		int res = 0;
		cout << "--" << endl;
	}

	return 0;
}