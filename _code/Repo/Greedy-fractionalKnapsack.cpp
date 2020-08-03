#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

struct Item {
	int value, weight;
	Item(int v, int w) {
		value = v;
		weight = w;
	}
};

bool sortByRatio(Item a, Item b) {
	return ((double) a.value / a.weight) > ((double) b.value / b.weight);
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n, w;
		cin >> n >> w;

		vector<Item> v;

		int vi, wi;
		for (int i = 0; i < n; i++) {
			cin >> vi >> wi;
			v.push_back(Item(vi, wi));
		}

		sort(v.begin(), v.end(), sortByRatio);

		// for (auto x: v)
		// 	cout << "(" << x.value << "," << x.weight << ") ";
		// cout << endl;

		double total_val = 0;
		for (int i = 0; i < n; i++) {

			if (w >= v[i].weight) {
				total_val += v[i].value;
				w -= v[i].weight;

			} else {
				total_val += ((double) v[i].value / v[i].weight) * w;
				break;
			}
		}

		cout << std::fixed;
	    cout << std::setprecision(2);
	    cout << total_val << endl;
	}

	return 0;
}

















