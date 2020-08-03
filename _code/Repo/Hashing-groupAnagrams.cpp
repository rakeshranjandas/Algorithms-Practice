#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string a, string b) {

	if (a.size() != b.size())
		return false;

	int *arr = (int* ) malloc(sizeof(int) * 26);
	memset(arr, 0, sizeof(int) * 26);

	for (auto c: a) {
		// cout << "--" << c << endl;
		arr[(c-'a')]++;
	}

	// for (int i = 0; i < 26; i++)
	// 	cout << arr[i] << " ";
	// cout << endl;

	for (auto c: b)
		arr[c-'a']--;


	// for (int i = 0; i < 26; i++)
	// 	cout << arr[i] << " ";
	// cout << endl;


	bool ret = true;
	for (int i = 0; i < 26; i++) {
		if (arr[i] != 0) {
			ret = false;
			break;
		}
	}

	free(arr);
	return ret;
}

void groupAnagrams(string s[], int n) {

	unordered_map<string, int> g;
	unordered_map<string, int> :: iterator it;

	g[s[0]] = 1;

	for (int i = 1; i < n; i++) {

		bool hasBeenGrouped = false;

		for (it = g.begin(); it != g.end(); it++) {

			if (isAnagram(it->first, s[i])) {

				it->second++;
				hasBeenGrouped = true;
				break;
			}
		}

		if (!hasBeenGrouped)
			g[s[i]] = 1;
	}

	vector<int> countArr;

	for (auto gg: g) {
		// cout << gg.first << "-" << gg.second << ", ";
		countArr.push_back(gg.second);
	}
	// cout << endl;

	sort(countArr.begin(), countArr.end());

	for (auto cnt: countArr)
		cout << cnt << " ";
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

	// cout << isAnagram("cat", "tac") << endl;

	while (t--) {
		int n;
		cin >> n;

		string s[n];
		for (int i = 0; i < n; i++)
			cin >> s[i];

		groupAnagrams(s, n);
	}

	return 0;
}