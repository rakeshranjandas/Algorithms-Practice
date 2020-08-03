#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define deb(x)	cout << #x << " " << x << endl;

bool sortByCmp (string a, string b) {
	return a.compare(b) <= 0;
}

int countDistinctSubstrings(string &str) {

	vector<string> substr_arr;
	int str_size = str.size();

	for (int i = 0; i < str_size; i++)
		substr_arr.push_back(str.substr(i));

	sort(substr_arr.begin(), substr_arr.end(), sortByCmp);

	vector<int> lcp(substr_arr.size());
	lcp[0] = 0;

	// for (auto x: substr_arr)
	// 	cout << x << endl;

	for (int i = 1; i < substr_arr.size(); i++) {
		int p = 0;
		string now_str = substr_arr[i];
		string prev_str = substr_arr[i-1];

		for (int j = 0; j < min(now_str.size(), prev_str.size()); j++) {
			if (now_str[j] == prev_str[j])
				p++;
			else
				break;
		}

		lcp[i] = p;
	}

	int distinct_str_count = 0;

	for (int i = 0; i < lcp.size(); i++)
		distinct_str_count += substr_arr[i].size() - lcp[i];

	return distinct_str_count + 1;
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

		string str;
		cin >> str;
		cout << countDistinctSubstrings(str) << endl;
	}

	return 0;
}