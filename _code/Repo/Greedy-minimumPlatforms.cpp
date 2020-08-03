#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

struct Train {
	int arr, dep;
	Train(int a, int d) {
		arr = a;
		dep = d;
	}
};

bool sortByEndTime(Train a, Train b) {
	return a.dep < b.dep;
}

int minPlatforms(int start[], int end[], int n) {

	vector<Train> v;

	for (int i = 0; i < n; i++)
		v.push_back(Train(start[i], end[i]));

	sort(v.begin(), v.end(), sortByEndTime);

	// for (auto x: v)
	// 	cout << x.arr << "," << x.dep << " ";
	// cout << endl;

	// set<int> s;
	// s.insert(v[0].dep);

	// for (int i = 1; i < v.size(); i++) {
	// 	auto it = s.upper_bound(v[i].arr);
	// 	// cout << (it==s.end() ? "at end" : to_string(*it)) << "<<--" << endl;

	// 	if (it == s.begin()) {
	// 		s.insert(v[i].dep);

	// 	} else {
	// 		s.erase(s.begin());
	// 		s.insert(v[i].dep);			
	// 	}

	// 	// deb(s.size());
	// 	// for (auto x: s)
	// 	// 	cout << x << ",";
	// 	// cout << endl;
	// }

	// return s.size();

	vector<int> p;
	p.push_back(v[0].dep);
	int k;

	for (int i = 1; i < v.size(); i++) {

		for (k = 0; k < p.size(); k++) {

			if (p[k] <= v[i].arr) {
				p[k] = v[i].dep;
				break;
			}
		}

		if (k == p.size())
			p.push_back(v[i].dep);
	}

	return p.size();
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
		int n;
		cin >> n;

		int start[n];
		for (int i = 0; i < n; i++)
			cin >> start[i];

		int end[n];
		for (int i = 0; i < n; i++)
			cin >> end[i];

		cout << minPlatforms(start, end, n) << endl;
	}

	return 0;
}