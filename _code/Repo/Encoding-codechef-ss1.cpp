#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
unordered_set<int> s;
unordered_map<int, long long int> m;

long long int countSteps(int n) {

	// cout << n << " " << endl;

	if (m.find(n) != m.end())
		return m[n];

	if (s.find(n) != s.end() || n < 0) {
		// cout << "invalid" << endl;
		return 0;
	}

	if (n == 0) {
		// cout << "return for 0" << endl;
		return 1;
	}

	int steps_1 = countSteps(n-1);
	int steps_2 = countSteps(n-2);
	int steps_3 = countSteps(n-3);


	// cout << "steps_1 " << steps_1 << endl;
	// cout << "steps_2 " << steps_2 << endl;
	// cout << "steps_3 " << steps_3 << endl;

	long long int steps = 
		(((steps_1 + steps_2) % M) + steps_3) % M;

	// cout << n << " - " << steps << endl;

	m[n] = steps;

	return steps;
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
		int n, k;
		cin >> n >> k;

		int ip;
		for (int i = 0; i < k; i++) {
			cin >> ip;
			s.insert(ip);
		}
		
		cout << countSteps(n) << endl;
		s.clear();
		m.clear();
	}

	return 0;
}