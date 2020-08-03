#include<iostream>
#include<bits/stdc++.h>
using namespace std;

unordered_map<int, int> m;

// int customCompare(int x, int y) {
// 	cout << "x " << x << " - " << m[x] << ", y " << y << " - " << m[y] << endl;
// 	return m[x] - m[y];
// }

// sort using a custom function object
struct {
    bool operator()(int a, int b) const
    {   
        return m[a] < m[b];
    }   
} customCompare;

void relativeSort(int a[], int an, int b[], int bn) {

	// Put b in an unordered map with order as value <O(n)>
	for (int i = 0; i < bn; i++)
		m[b[i]] = i;

	// cout << "map = " << endl;
	// for (auto mc : m) {
	// 	cout << mc.first << "->" << mc.second << endl;
	// }

	// Separate elements that are in b and not in b
	int r = an;

	for (int i = an-1; i >= 0; i--) {
		if (m.find(a[i]) == m.end()) {
			int temp = a[i];
			a[i] = a[r-1];
			a[r-1] = temp;
			r--;
		}
	}

	// cout << r << endl;

	// Sort partition not in b
	if (r < an)
		sort(a+r, a+an);

	// Print
	// for (int i = 0; i < an; i++)
	// 	cout << a[i] << " ";
	// cout << endl;


	// Sort partition in b
	sort(a, a+r, customCompare);

	// Print
	for (int i = 0; i < an; i++)
		cout << a[i] << " ";
	cout << endl;
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
		m.clear();

		int n1, n2;
		cin >> n1 >> n2;

		int a1[n1], a2[n2];

		for (int i = 0; i < n1; i++)
			cin >> a1[i];

		for (int i = 0; i < n2; i++)
			cin >> a2[i];

		relativeSort(a1, n1, a2, n2);
	}

	return 0;
}