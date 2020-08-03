#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void commonElements(int a1[], int n1, int a2[], int n2, int a3[], int n3) {

	unordered_map<int, unordered_set<int>> m;
	bool found = false;

	for (int i = 0; i < n1; i++)
		m[a1[i]].insert(1);

	for (int i = 0; i < n2; i++)
		m[a2[i]].insert(2);

	for (int i = 0; i < n3; i++)
		m[a3[i]].insert(3);


	for (int i = 0; i < n1; i++) 
		if (m[a1[i]].size() == 3) {
			found = true;
			cout << a1[i] << " ";
			m.erase(a1[i]);
		}

	if (!found)
		cout << "-1";

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
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;

		int a1[n1], a2[n2], a3[n3];
		for (int i = 0; i < n1; i++)
			cin >> a1[i];
		for (int i = 0; i < n2; i++)
			cin >> a2[i];
		for (int i = 0; i < n3; i++)
			cin >> a3[i];

		commonElements(a1, n1, a2, n2, a3, n3);
	}

	return 0;
}