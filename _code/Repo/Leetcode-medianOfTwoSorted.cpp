#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

double medianOfOneArray(vector<int> &v) {
	int v_size = v.size();

	if (v_size == 0)
		return 0;

	if (v_size % 2 == 1)
		return v[v_size/2];

	return ((double)(v[v_size/2] + v[(v_size/2)-1])) / 2;
}

bool allSame(vector<int> &v1, vector<int> &v2) {
	int num = v1[0];

	for (auto x: v1)
		if (x != num)
			return false;

	for (auto x: v2)
		if (x != num)
			return false;

	return true;
}

bool valid(int i, vector<int> &v) {
	return i >= 0 && i < v.size();
}

double medianOfSorted(vector<int> &v1, vector<int> &v2) {

	if (v1.size() == 0)
		return medianOfOneArray(v2);

	if (v2.size() == 0)
		return medianOfOneArray(v1);

	// if (allSame(v1, v2))
	// 	return v1[0];

	int v1_size = v1.size(), v2_size = v2.size();
	int total = (v1_size + v2_size);

	int half = total - (total/2), mid;

	int l = 0, r = v1_size, l1, l2, r1, r2;
	int numl1, numl2, numr1, numr2;

	double median = 0;

	while (l <= r) {
		mid = (l+r) / 2;
		deb(l);
		deb(r);
		deb(mid);

		l1 = mid-1, l2 = half-mid-1;
		r1 = l1+1, r2 = l2+1;

		numl1 = numl2 = INT_MIN;
		numr1 = numr2 = INT_MAX;

		if (valid(l1, v1))
			numl1 = v1[l1];

		if (valid(l2, v2))
			numl2 = v2[l2];

		if (valid(r1, v1))
			numr1 = v1[r1];

		if (valid(r2, v2))
			numr2 = v2[r2];

		deb(l1);
		deb(l2);
		deb(r1);
		deb(r2);
		deb(numl1);
		deb(numl2);
		deb(numr1);
		deb(numr2);

		if (numl1 <= min(numr1, numr2) && numl2 <= min(numr1, numr2)) {
			deb(total);

			if (total%2 == 1)
				median = max(numl1, numl2);
			else {

				deb(min(numr1, numr2));
				median = (((double)(max(numl1, numl2)) + (double)(min(numr1, numr2)))) / 2;
			}

			break;

		} else {

			if (numl1 >= numr2)
				r = mid;
			else
				l = mid+1;
		}
	}

	return median;
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
		int n1;
		cin >> n1;
		
		vector<int> v1;
		int ip;
		for (int i = 0; i < n1; i++) {
			cin >> ip;
			v1.push_back(ip);
		}


		int n2;
		cin >> n2;
		vector<int> v2;
		for (int i = 0; i < n2; i++) {
			cin >> ip;
			v2.push_back(ip);
		}

		cout << medianOfSorted(v1, v2) << endl;
	}

	return 0;
}