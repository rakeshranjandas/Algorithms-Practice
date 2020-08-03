#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void diffInArr(long long int a1[], int n1, long long int a2[], int n2) {

	unordered_set<long long int> s;

	for (int i = 0; i < n1; i++)
		s.insert(a1[i]);

	unordered_set<long long int> :: iterator it;
	for (int i = 0; i < n2; i++) {
		it = s.find(a2[i]);

		if (it != s.end())
			s.erase(it);
	}

	for (int i = 0; i < n1; i++)
		if (s.find(a1[i]) != s.end())
			cout << a1[i] << ' ';

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
		int n1, n2;
		cin >> n1 >> n2;

		long long int a1[n1], a2[n2];

		for (int i = 0; i < n1; i++)
			cin >> a1[i];

		for (int i = 0; i < n2; i++)
			cin >> a2[i];

		diffInArr(a1, n1, a2, n2);

	}

	return 0;
}