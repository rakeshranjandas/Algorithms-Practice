#include<iostream>
#include<bits/stdc++.h>
using namespace std;

unordered_map<char, int> m = {
	{'!', 1},
	{'#', 2},
	{'$', 3},
	{'%', 4},
	{'&', 5},
	{'*', 6},
	{'@', 7},
	{'^', 8},
	{'~', 9}
};

class customSort {
	public: bool operator() (char a, char b) {
		return m[a] < m[b];
	}
};

void matchNutsAndBolts(char nuts[], char bolts[], int n) {

	map<char, int, customSort> nutsMap;

	for (int i = 0; i < n; i++)
		nutsMap[nuts[i]] = -1;

	for (int i = 0; i < n; i++)
		if (nutsMap.find(bolts[i]) != nutsMap.end())
			nutsMap[bolts[i]] = i;

	for (auto nut : nutsMap)
		cout << nut.first << " ";
	cout << endl;

	for (auto nut : nutsMap)
		cout << bolts[nut.second] << " ";
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
		int n;
		cin >> n;

		char nuts[n];
		for (int i = 0; i < n; i++)
			cin >> nuts[i];

		char bolts[n];
		for (int i = 0; i < n; i++)
			cin >> bolts[i];

		matchNutsAndBolts(nuts, bolts, n);
	}

	return 0;
}